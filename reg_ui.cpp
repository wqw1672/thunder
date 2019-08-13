#include "reg_ui.h"
extern QTcpSocket *tcpclient ;
extern QString ip;
extern int duankou;
reg_ui::reg_ui(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(500,765);
    this->setWindowTitle("����ս��");
    palette_reg=new QPalette;

    palette_reg->setBrush(QPalette::Background,QBrush(QPixmap("images/widget/Bag_Bg5.png")));//�ñ�ˢ�����ñ���
    this->setPalette(*palette_reg);

    yesbtn=new QPushButton(this);
    yesbtn->setGeometry(50,700,142,53);
    yesbtn->setStyleSheet("QPushButton{border-image: url(images/btn/OK.png);}"
                              "QPushButton:hover{border-image: url(images/btn/OK1.png);}"
                              "QPushButton:pressed{border-image: url(images/btn/OK.png);}");

   connect(yesbtn,SIGNAL(clicked()),this,SLOT(yes_slot()));

    //retbtn = new QPushButton(this);

    exitbtn = new QPushButton(this);
    exitbtn->setIcon(QIcon("images/btn/sz_back2.png"));
    exitbtn->setIconSize(QSize(45,45));
    exitbtn->setFocusPolicy(Qt::NoFocus);//ȥ�������
    exitbtn->setFlat(true); //�����׿�ȥ��
    exitbtn->move(420,30);
    //ȥ�������ť����ֵİ�ɫ����
    exitbtn->setStyleSheet("QPushButton{background-color:transparent;border:0px;color:white}");
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_on()));


    connect(exitbtn,SIGNAL(clicked()),this,SLOT(backSignal()));

    username_edit=new QLineEdit("",this);
    username_edit->setGeometry(180,195,275,45);
    username_edit->setPlaceholderText("�������û���");
    username_edit->setStyleSheet("font-size:28px;borde:1px;background-color:rgba(0,0,0,0)");
    username_edit->setMaxLength(12);

    gamename_edit=new QLineEdit("",this);
    gamename_edit->setGeometry(180,260,275,30);
    gamename_edit->setPlaceholderText("�����ǳ�");
    gamename_edit->setStyleSheet("font-size:20px;borde:1px;background-color:rgba(0,0,0,0)");
    gamename_edit->setMaxLength(12);

    userpwd_edit=new QLineEdit("",this);
    userpwd_edit->setGeometry(180,320,275,30);
    userpwd_edit->setEchoMode(QLineEdit::Password);
    userpwd_edit->setPlaceholderText("��������");
    userpwd_edit->setStyleSheet("font-size:20px;borde:1px;background-color:rgba(0,0,0,0)");
    userpwd_edit->setValidator(new QIntValidator(0,99999999,this));
    userpwd_edit->setMaxLength(8);

    pwdagain_edit=new QLineEdit("",this);
    pwdagain_edit->setGeometry(180,380,275,30);
    pwdagain_edit->setEchoMode(QLineEdit::Password);
    pwdagain_edit->setPlaceholderText("���ٴ�������");
    pwdagain_edit->setStyleSheet("font-size:28px;borde:1px;background-color:rgba(0,0,0,0)");
    pwdagain_edit->setValidator(new QIntValidator(0,99999999,this));
    pwdagain_edit->setMaxLength(8);



    question_label = new QLabel(this);
    question_label->setText("��ĵ绰�����Ƕ��٣�");
    question_label->move(190,440);


    answer_edit=new QLineEdit("",this);
    answer_edit->setGeometry(180,500,275,30);
    answer_edit->setPlaceholderText("�������");
    answer_edit->setStyleSheet("font-size:20px;borde:1px;background-color:rgba(0,0,0,0)");
    answer_edit->setMaxLength(12);

    this->setWindowFlags(Qt::CustomizeWindowHint);
}

void reg_ui::yes_slot()
{
    char buff[1024];
    ithead.head=2;
    memcpy(buff,&ithead,sizeof(struct pub_head));//���ͷ��
    strcpy(message.name,username_edit->text().toStdString().c_str());//�û���
    strcpy(message.username,gamename_edit->text().toStdString().c_str());//�û���
    strcpy(message.passwd,gamename_edit->text().toStdString().c_str());//�û���
    strcpy(message.answer,answer_edit->text().toStdString().c_str());//�û���


    memcpy(buff+sizeof(struct pub_head),&message,sizeof(struct STU));
    if(userpwd_edit->text()!=pwdagain_edit->text())
    {
        newmessage=new QMessageBox(this);
        newmessage->setText("��������������д��ͬ");
        newmessage->exec();
        return ;
    }
    else if(userpwd_edit->text()==NULL||username_edit->text()==NULL||gamename_edit->text()==NULL||answer_edit->text()==NULL)
    {
        newmessage=new QMessageBox(this);
        newmessage->setText("��д����Ϊ��");
        newmessage->exec();
        return ;
    }
    tcpclient->connectToHost(ip,duankou);

    tcpclient->write(buff,sizeof(struct STU)+sizeof(struct pub_head));
    timer->start(1000);

}
void reg_ui::ret_slot()
{

}
void reg_ui::exit_reg_slot()
{

}
reg_ui::~reg_ui()
{

}
void reg_ui::backSignal()
{
    timer->stop();
    emit regSignal();//���͸��������źţ��㲥�źţ�
}
void reg_ui::time_on()
{

    char *ch;
    ch=tcpclient->readAll().data();
    qDebug()<<ch;
    qDebug()<<"11111111";


    if(strcmp(ch,"3")==0)
    {
        newmessage=new QMessageBox(this);
        newmessage->setText("��ע����û����Ѿ�����");
        newmessage->exec();
    }
     else if(strcmp(ch,"4")==0)
    {
        newmessage=new QMessageBox(this);
        newmessage->setText("��ע����ǳ��Ѿ�����");
        newmessage->exec();
    }
    else if(strcmp(ch,"0")==0)
   {
       newmessage=new QMessageBox(this);
       newmessage->setText("��ϲע��ɹ�");
       newmessage->exec();
   }
}
