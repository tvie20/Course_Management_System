#ifndef NEUMORPHICBUTTON_H
#define NEUMORPHICBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>

class NeumorphicButton : public QPushButton {
    Q_OBJECT
public:
    explicit NeumorphicButton(const QString &text, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawShadow(QPainter &painter, const QRect &rect, bool inset);
};

#endif // NEUMORPHICBUTTON_H
