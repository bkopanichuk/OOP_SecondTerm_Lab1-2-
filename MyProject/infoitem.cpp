#include "infoitem.h"
#include "ui_infoitem.h"

InfoItem::InfoItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoItem)
{
    ui->setupUi(this);

    w41 = new AddComponent();
//    w4 = new InfoItem();

    connect(this, SIGNAL(SendBigData(bigdata*)), w41, SLOT(RecieveBigData(bigdata*)));
    connect(this, SIGNAL(SendItem(item*)), w41, SLOT(RecieveItem(item*)));
    connect(w41, SIGNAL(close()), this, SLOT(UpdateInfo()));
/*    connect(this, SIGNAL(SendBigData(bigdata*)), w4, SLOT(RecieveBigData(bigdata*)));
    connect(this, SIGNAL(SendItem(item*)), w4, SLOT(RecieveItem(item*))); */
}

InfoItem::~InfoItem()
{
    delete ui;
}

bigdata * bdw4; //база данных
item * cw4; //выбраный товар

void InfoItem::RecieveBigData(bigdata * bd4){
    bdw4 = bd4;
}

void InfoItem::UpdateInfo(){
    ui->listWidget->clear();
    for (auto i = 0; i < cw4->components.size(); i++){
        ui->listWidget->addItem(cw4->components[i]->name);
    }

    ui->listWidget_2->clear();
    for (auto i = 0; i < cw4->parents.size(); i++){
        ui->listWidget_2->addItem(cw4->parents[i]->name);
    }
}

void InfoItem::RecieveItem(item * it4){
    cw4 = it4;

    ui->label->setText("Info about " + cw4->name);
    UpdateInfo();
}

void InfoItem::on_pushButton_clicked()
{
    w41->show();
    emit SendBigData(bdw4);
    emit SendItem(cw4);
}

/*void InfoItem::on_listWidget_itemActivated(QListWidgetItem *item)
{
    w4->show();
    emit SendBigData(bdw4);
    emit SendItem(bdw4->search_item(item->text()));
    close();
} */
