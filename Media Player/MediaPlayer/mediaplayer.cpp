#include "mediaplayer.h"
#include "ui_mediaplayer.h"

MediaPlayer::MediaPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MediaPlayer)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    slider = new QSlider(this);
    bar = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
    ui->statusBar->addPermanentWidget(bar);


    connect(ui->actionOpen,SIGNAL(triggered()),this, SLOT(OpenFile()));
    connect(ui->actionPause, SIGNAL(triggered()),this, SLOT(Pause()));
    connect(ui->actionPlay, SIGNAL(triggered()),this, SLOT(Play()));
    connect(ui->actionStop, SIGNAL(triggered()),this,SLOT(Stop()));
    connect(player,&QMediaPlayer::durationChanged, slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged, slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved, player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged, bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged, bar,&QProgressBar::setValue);

}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}

void MediaPlayer::OpenFile(){
    QString file_path = QFileDialog::getOpenFileName(this, "Open a file", "", "(*.*)");
    Stop();
    player->setMedia(QUrl::fromLocalFile(file_path));
    Play();

}
void MediaPlayer::Pause(){
    player->pause();
    ui->statusBar->showMessage("Paused");

}
void MediaPlayer::Play(){
    player->play();
    ui->statusBar->showMessage("Playing");
}
void MediaPlayer::Stop(){
    player->stop();
    ui->statusBar->showMessage("Stopped");
}
