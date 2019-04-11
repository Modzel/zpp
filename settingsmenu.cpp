#include "settingsmenu.h"

SettingsMenu::SettingsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsMenu)
{
    ui->setupUi(this);
}

SettingsMenu::~SettingsMenu()
{
    delete ui;
}

void SettingsMenu::on_backButton_clicked()
{
    emit back_option_selected(SETTINGS_BACK);
}

void SettingsMenu::on_blocksComboBox_activated(const QString &blocks)
{
    emit number_of_blocks_changed(blocks);
}

void SettingsMenu::on_soundComboBox_activated(int index)
{
    emit sound_setting_changed(index);
}
