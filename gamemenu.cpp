#include "gamemenu.h"
#include "ui_gamemenu.h"

GameMenu::GameMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameMenu)
{
    ui->setupUi(this);

}

GameMenu::~GameMenu()
{
    delete ui;
}

void GameMenu::on_buttonGame_clicked()
{
    emit menu_option_selected(START);
}

void GameMenu::on_buttonSettings_clicked()
{
    emit menu_option_selected(SETTINGS);
}
