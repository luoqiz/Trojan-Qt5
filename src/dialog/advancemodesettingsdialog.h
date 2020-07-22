#ifndef ADVANCEMODESETTINGSDIALOG_H
#define ADVANCEMODESETTINGSDIALOG_H

#include <QDialog>
#include "confighelper.h"

namespace Ui {
class AdvanceModeSettingsDialog;
}

class AdvanceModeSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdvanceModeSettingsDialog(ConfigHelper *ch, QWidget *parent = 0);
    ~AdvanceModeSettingsDialog();

private:
    Ui::AdvanceModeSettingsDialog *ui;
    ConfigHelper *helper;

private slots:
    void onAccepted();
};

#endif // ADVANCEMODESETTINGSDIALOG_H
