#include "neumorphicbutton.h"

NeumorphicButton::NeumorphicButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent) {
    setStyleSheet(R"(
        QPushButton {
            border: none;
            border-radius: 20px;
            background-color: #e0e0e0;
            padding: 10px;
        }
    )");
}

void NeumorphicButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect rect = this->rect();

    // Draw shadows
    drawShadow(painter, rect, true);  // Top-left shadow
    drawShadow(painter, rect, false); // Bottom-right shadow

    // Draw the base rectangle with rounded corners
    painter.setBrush(QColor("#e0e0e0"));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect.adjusted(5, 5, -5, -5), 20, 20);

    // Draw the button text and other elements
    QPushButton::paintEvent(event);
}

void NeumorphicButton::drawShadow(QPainter &painter, const QRect &rect, bool inset) {
    QLinearGradient gradient;
    if (inset) {
        gradient = QLinearGradient(rect.topLeft(), rect.bottomRight());
        gradient.setColorAt(0.0, QColor(255, 255, 255, 180)); // Light shadow
        gradient.setColorAt(1.0, QColor(190, 190, 190, 180)); // Dark shadow
    } else {
        gradient = QLinearGradient(rect.bottomRight(), rect.topLeft());
        gradient.setColorAt(0.0, QColor(190, 190, 190, 180)); // Dark shadow
        gradient.setColorAt(1.0, QColor(255, 255, 255, 180)); // Light shadow
    }

    painter.setBrush(gradient);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(rect.adjusted(5, 5, -5, -5), 20, 20);
}
