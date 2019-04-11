#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "gamemenuitems.h"
#include "ui_settingsmenu.h"

namespace Ui {
class SettingsMenu;
}

class SettingsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsMenu(QWidget *parent = nullptr);
    ~SettingsMenu();

signals:
    void back_option_selected(GameMenuItems option);
    void number_of_blocks_changed(QString blocks);
    void sound_setting_changed(int soundSetting);

private slots:
    void on_backButton_clicked();

    void on_blocksComboBox_activated(const QString &arg1);

    void on_soundComboBox_activated(int index);

private:
    Ui::SettingsMenu *ui;
};

#endif // SETTINGS_H
