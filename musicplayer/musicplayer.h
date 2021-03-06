#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QWidget>
#include <QMediaPlayer>

class VolumeButton;

QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)
QT_FORWARD_DECLARE_CLASS(QAbstractButton)


class MusicPlayer : public QWidget
{
    Q_OBJECT
public:
    MusicPlayer(QWidget *parent = 0);

public slots:
    void openFile();
    void playFile(const QString& filePath);
    void togglePlayback();
    void seekForward();
    void seekBackward();

protected:
    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void stylize();
    void updateState(QMediaPlayer::State state);
    void updatePosition(qint64 position);
    void updateDuration(qint64 duration);
    void setPosition(int position);
    void updateInfo();
    void handleError();


private:
    void createWidgets();
    void createShortcuts();

    QMediaPlayer mediaPlayer;
    QAbstractButton *playButton;
    VolumeButton *volumeButton;
    QSlider *positionSlider;
    QLabel *positionLabel;
    QLabel *infoLabel;
    QPoint offset;
};

#endif // MUSICPLAYER_H
