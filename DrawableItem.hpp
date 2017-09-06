#ifndef DRAWABLEITEM_HPP
#define DRAWABLEITEM_HPP

#include <QGraphicsItem>

class QGraphicsPathItem;

class DrawableItem : public QGraphicsItem {

public:
    DrawableItem(QGraphicsItem* parent = 0);

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter */*painter*/, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/) override;

    void setSize(const QSizeF& size);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QSizeF m_size;
    QGraphicsPathItem* m_activePath = nullptr;
};




#endif // DRAWABLEITEM_HPP
