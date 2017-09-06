#include "DrawableItem.hpp"

#include <QPen>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>


DrawableItem::DrawableItem(QGraphicsItem *parent)
    : QGraphicsItem(parent = 0)
{
    setFlag(ItemClipsChildrenToShape);
    setFlag(ItemHasNoContents);
}

QRectF DrawableItem::boundingRect() const {
    return {{0,0}, m_size};
}

void DrawableItem::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) {
    Q_ASSERT(false && "ItemHasNoContents flag is set. It's not expected to recive this call");
}

void DrawableItem::setSize(const QSizeF &size) {
    prepareGeometryChange();
    m_size = size;
}

void DrawableItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    m_activePath = new QGraphicsPathItem(this);
    m_activePath->setPen(QPen(Qt::GlobalColor(rand()%17+2), 2.0));
    m_activePath->setPath(QPainterPath(event->pos()));
}

void DrawableItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if(!m_activePath) {
        QGraphicsItem::mouseMoveEvent(event);
        return;
    }

    auto path = m_activePath->path();
    path.lineTo(event->pos());
    m_activePath->setPath(path);
}

void DrawableItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if(!m_activePath) {
        QGraphicsItem::mouseReleaseEvent(event);
        return;
    }
    m_activePath = nullptr;
}

