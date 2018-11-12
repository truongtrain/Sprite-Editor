/********************************************************************************
** Form generated from reading UI file 'spriteeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEEDITORWINDOW_H
#define UI_SPRITEEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteEditorWindow
{
public:
    QWidget *centralWidget;
    QPushButton *chooseColorBox;
    QLabel *colorLabel;
    QSlider *resolutionSlider;
    QLabel *resolutionLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *frameLayout;
    QListWidget *framesList;
    QPushButton *addFrameButton;
    QPushButton *removeFrameButton;
    QRadioButton *penButton;
    QRadioButton *eraserButton;
    QRadioButton *selectionButton;
    QPushButton *duplicateButton;
    QLabel *framesListLabel;
    QCheckBox *drawMirrorCheckBox;
    QSlider *frameRateSlider;
    QLabel *frameRateLabel;
    QPushButton *popOutButton;
    QLabel *previewLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpriteEditorWindow)
    {
        if (SpriteEditorWindow->objectName().isEmpty())
            SpriteEditorWindow->setObjectName(QStringLiteral("SpriteEditorWindow"));
        SpriteEditorWindow->resize(1164, 875);
        SpriteEditorWindow->setMinimumSize(QSize(300, 300));
        SpriteEditorWindow->setMouseTracking(true);
        centralWidget = new QWidget(SpriteEditorWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chooseColorBox = new QPushButton(centralWidget);
        chooseColorBox->setObjectName(QStringLiteral("chooseColorBox"));
        chooseColorBox->setGeometry(QRect(870, 430, 151, 31));
        colorLabel = new QLabel(centralWidget);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));
        colorLabel->setEnabled(true);
        colorLabel->setGeometry(QRect(1030, 420, 50, 50));
        colorLabel->setStyleSheet(QLatin1String("border-color: rgb(238, 238, 236);\n"
"background-color: rgb(0, 0, 0);"));
        colorLabel->setLineWidth(5);
        resolutionSlider = new QSlider(centralWidget);
        resolutionSlider->setObjectName(QStringLiteral("resolutionSlider"));
        resolutionSlider->setGeometry(QRect(880, 520, 221, 21));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(resolutionSlider->sizePolicy().hasHeightForWidth());
        resolutionSlider->setSizePolicy(sizePolicy);
        resolutionSlider->setMaximum(3);
        resolutionSlider->setSingleStep(0);
        resolutionSlider->setPageStep(1);
        resolutionSlider->setValue(3);
        resolutionSlider->setSliderPosition(3);
        resolutionSlider->setOrientation(Qt::Horizontal);
        resolutionSlider->setTickPosition(QSlider::TicksBelow);
        resolutionSlider->setTickInterval(0);
        resolutionLabel = new QLabel(centralWidget);
        resolutionLabel->setObjectName(QStringLiteral("resolutionLabel"));
        resolutionLabel->setGeometry(QRect(930, 490, 111, 21));
        QFont font;
        font.setPointSize(14);
        resolutionLabel->setFont(font);
        resolutionLabel->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 831, 801));
        frameLayout = new QGridLayout(gridLayoutWidget);
        frameLayout->setSpacing(6);
        frameLayout->setContentsMargins(11, 11, 11, 11);
        frameLayout->setObjectName(QStringLiteral("frameLayout"));
        frameLayout->setContentsMargins(0, 0, 0, 0);
        framesList = new QListWidget(centralWidget);
        framesList->setObjectName(QStringLiteral("framesList"));
        framesList->setGeometry(QRect(870, 580, 221, 192));
        framesList->setEditTriggers(QAbstractItemView::DoubleClicked);
        framesList->setDragEnabled(true);
        framesList->setDragDropMode(QAbstractItemView::DragDrop);
        framesList->setDefaultDropAction(Qt::MoveAction);
        framesList->setSelectionBehavior(QAbstractItemView::SelectRows);
        addFrameButton = new QPushButton(centralWidget);
        addFrameButton->setObjectName(QStringLiteral("addFrameButton"));
        addFrameButton->setGeometry(QRect(1100, 580, 51, 25));
        removeFrameButton = new QPushButton(centralWidget);
        removeFrameButton->setObjectName(QStringLiteral("removeFrameButton"));
        removeFrameButton->setGeometry(QRect(1090, 610, 71, 25));
        penButton = new QRadioButton(centralWidget);
        penButton->setObjectName(QStringLiteral("penButton"));
        penButton->setGeometry(QRect(870, 330, 112, 23));
        eraserButton = new QRadioButton(centralWidget);
        eraserButton->setObjectName(QStringLiteral("eraserButton"));
        eraserButton->setGeometry(QRect(870, 360, 112, 23));
        selectionButton = new QRadioButton(centralWidget);
        selectionButton->setObjectName(QStringLiteral("selectionButton"));
        selectionButton->setGeometry(QRect(870, 390, 112, 23));
        duplicateButton = new QPushButton(centralWidget);
        duplicateButton->setObjectName(QStringLiteral("duplicateButton"));
        duplicateButton->setGeometry(QRect(1090, 640, 81, 25));
        framesListLabel = new QLabel(centralWidget);
        framesListLabel->setObjectName(QStringLiteral("framesListLabel"));
        framesListLabel->setGeometry(QRect(940, 550, 71, 21));
        framesListLabel->setFont(font);
        drawMirrorCheckBox = new QCheckBox(centralWidget);
        drawMirrorCheckBox->setObjectName(QStringLiteral("drawMirrorCheckBox"));
        drawMirrorCheckBox->setGeometry(QRect(1000, 360, 141, 23));
        frameRateSlider = new QSlider(centralWidget);
        frameRateSlider->setObjectName(QStringLiteral("frameRateSlider"));
        frameRateSlider->setGeometry(QRect(880, 310, 221, 21));
        sizePolicy.setHeightForWidth(frameRateSlider->sizePolicy().hasHeightForWidth());
        frameRateSlider->setSizePolicy(sizePolicy);
        frameRateSlider->setMaximum(10);
        frameRateSlider->setSingleStep(0);
        frameRateSlider->setPageStep(1);
        frameRateSlider->setValue(0);
        frameRateSlider->setSliderPosition(0);
        frameRateSlider->setOrientation(Qt::Horizontal);
        frameRateSlider->setTickPosition(QSlider::TicksBelow);
        frameRateSlider->setTickInterval(0);
        frameRateLabel = new QLabel(centralWidget);
        frameRateLabel->setObjectName(QStringLiteral("frameRateLabel"));
        frameRateLabel->setGeometry(QRect(910, 280, 151, 21));
        frameRateLabel->setFont(font);
        frameRateLabel->setAlignment(Qt::AlignCenter);
        popOutButton = new QPushButton(centralWidget);
        popOutButton->setObjectName(QStringLiteral("popOutButton"));
        popOutButton->setGeometry(QRect(920, 250, 131, 25));
        previewLabel = new QLabel(centralWidget);
        previewLabel->setObjectName(QStringLiteral("previewLabel"));
        previewLabel->setGeometry(QRect(880, 20, 261, 201));
        SpriteEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpriteEditorWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1164, 22));
        SpriteEditorWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpriteEditorWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SpriteEditorWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SpriteEditorWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SpriteEditorWindow->setStatusBar(statusBar);

        retranslateUi(SpriteEditorWindow);

        QMetaObject::connectSlotsByName(SpriteEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpriteEditorWindow)
    {
        SpriteEditorWindow->setWindowTitle(QApplication::translate("SpriteEditorWindow", "SpriteEditorWindow", nullptr));
        chooseColorBox->setText(QApplication::translate("SpriteEditorWindow", "Choose Color", nullptr));
        colorLabel->setText(QString());
        resolutionLabel->setText(QApplication::translate("SpriteEditorWindow", "Resolution", nullptr));
        addFrameButton->setText(QApplication::translate("SpriteEditorWindow", "Add", nullptr));
        removeFrameButton->setText(QApplication::translate("SpriteEditorWindow", "Remove", nullptr));
        penButton->setText(QApplication::translate("SpriteEditorWindow", "Pen", nullptr));
        eraserButton->setText(QApplication::translate("SpriteEditorWindow", "Eraser", nullptr));
        selectionButton->setText(QApplication::translate("SpriteEditorWindow", "Selection", nullptr));
        duplicateButton->setText(QApplication::translate("SpriteEditorWindow", "Duplicate", nullptr));
        framesListLabel->setText(QApplication::translate("SpriteEditorWindow", "Frames", nullptr));
        drawMirrorCheckBox->setText(QApplication::translate("SpriteEditorWindow", "Draw Mirrored", nullptr));
        frameRateLabel->setText(QApplication::translate("SpriteEditorWindow", "Frame Rate (fps)", nullptr));
        popOutButton->setText(QApplication::translate("SpriteEditorWindow", "Full Size Preview", nullptr));
        previewLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SpriteEditorWindow: public Ui_SpriteEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITORWINDOW_H
