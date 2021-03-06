#ifndef OPENER_H
#define OPENER_H

#include "ui_opener.h"
#include <QFile>
#include <QJsonArray>
#include <QFileDialog>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QKeyEvent>

class Opener : public QDialog, private Ui::Opener
{
    Q_OBJECT

public:
    explicit Opener(QWidget *parent = 0);
    QList<QUrl> getUrls();
    QStringList getFrames();
    void setTitle(QString t);
    static QStringList getSequence(QString fichierBase);
    bool isMovie();
    QString getMovie();

private slots:
    void on_file_clicked();
    void on_folder_clicked();
    void on_favsList_itemDoubleClicked();
    void on_recentList_itemDoubleClicked(QListWidgetItem *item);
    void on_addToFavs_clicked();
    void on_upButton_clicked();
    void on_downButton_clicked();

private:
    QStringList frames;
    QFile *favsFile;
    QJsonArray getFavs();
    void setFavs(QJsonArray favsArray);
    QJsonArray getRecents();
    void setRecent(QJsonArray recentArray);
    void addRecent();
    void refreshFavs();
    bool movie;
    QString movieFile;
protected:
    virtual void keyPressEvent(QKeyEvent *event);

};

#endif // OPENER_H
