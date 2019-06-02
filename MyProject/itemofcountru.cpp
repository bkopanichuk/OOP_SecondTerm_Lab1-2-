#include "itemofcountru.h"
#include "ui_itemofcountru.h"

ItemOfCountru::ItemOfCountru(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemOfCountru)
{
    ui->setupUi(this);

    w4 = new InfoItem();

    connect(this, SIGNAL(SendItem(item*)), w4, SLOT(RecieveItem(item*)));
    connect(this, SIGNAL(SendBigData(bigdata*)), w4, SLOT(RecieveBigData(bigdata*)));
}

ItemOfCountru::~ItemOfCountru()
{
    delete ui;
}

bigdata * bdw32; //база данных
records * cw32; //выбраный товар

void ItemOfCountru::RecieveBigData(bigdata * bd32){
    bdw32 = bd32;
}

void ItemOfCountru::RecieveItem(records * it32){
    cw32 = it32;

    ui->label->clear();
    ui->label->setText("You choose item: " + cw32->element->name);
}

void ItemOfCountru::on_pushButton_clicked()
{
    w4->show();
    emit SendBigData(bdw32);
    emit SendItem(cw32->element);
    close();
}
