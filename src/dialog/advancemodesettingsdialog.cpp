#include "advancemodesettingsdialog.h"
#include "ui_advancemodesettingsdialog.h"
#include "modehelper.h"

#include <QListView>

AdvanceModeSettingsDialog::AdvanceModeSettingsDialog(ConfigHelper *ch, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdvanceModeSettingsDialog),
    helper(ch)
{
    ui->setupUi(this);

    helper->readAdvanceModeSettings();

    ui->addressEdit->setText(helper->getTUNTAPSettings().address);
    ui->netmaskEdit->setText(helper->getTUNTAPSettings().netmask);
    ui->gatewayEdit->setText(helper->getTUNTAPSettings().gateway);
    ui->dnsEdit->setText(helper->getTUNTAPSettings().dns);
    ui->customDNSCB->setChecked(helper->getTUNTAPSettings().customDNS);
    ui->fakeDNSCB->setChecked(helper->getTUNTAPSettings().fakeDNS);

    ui->serverEdit->setText(helper->getSTUNSettings().address);
    ui->portSB->setValue(helper->getSTUNSettings().port);

    ui->modeCB->setCurrentIndex(helper->getModeSettings().mode);
    ui->redirectorModeCB->addItems(ModeHelper::listAllModes());
    ui->redirectorModeCB->setCurrentText(helper->getModeSettings().redirectorMode);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AdvanceModeSettingsDialog::onAccepted);

    this->adjustSize();
}

AdvanceModeSettingsDialog::~AdvanceModeSettingsDialog()
{
    delete ui;
}

void AdvanceModeSettingsDialog::onAccepted()
{
    TUNTAPSettings tSettings = helper->getTUNTAPSettings();
    tSettings.address = ui->addressEdit->text();
    tSettings.netmask = ui->netmaskEdit->text();
    tSettings.gateway = ui->gatewayEdit->text();
    tSettings.dns = ui->dnsEdit->text();
    tSettings.customDNS = ui->customDNSCB->isChecked();
    tSettings.fakeDNS = ui->fakeDNSCB->isChecked();

    STUNSettings sSettings = helper->getSTUNSettings();
    sSettings.address = ui->serverEdit->text();
    sSettings.port = ui->portSB->value();

    ModeSettings mSettings = helper->getModeSettings();
    mSettings.mode = ui->modeCB->currentIndex();
    mSettings.redirectorMode = ui->redirectorModeCB->currentText();

    helper->setAdvanceModeSettings(tSettings, sSettings, mSettings);

    this->accept();
}
