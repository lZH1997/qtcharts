#ifndef QXYSERIES_H_
#define QXYSERIES_H_

#include "qchartglobal.h"
#include "qseries.h"
#include <QDebug>
#include <QPen>
#include <QBrush>

QTCOMMERCIALCHART_BEGIN_NAMESPACE

class QTCOMMERCIALCHART_EXPORT QXYSeries : public QSeries
{
    Q_OBJECT
protected:
    QXYSeries(QObject* parent=0);
    virtual ~QXYSeries();

public:
    void add(qreal x, qreal y);
    void add(const QPointF& point);
    void add(const QList<QPointF> points);
    void replace(qreal x,qreal y);
    void replace(const QPointF& point);
    void remove(qreal x);
    void remove(const QPointF& point);
    void removeAll();

    int count() const;
    qreal x(int pos) const;
    qreal y(int pos) const;
    QList<QPointF> data();

    QXYSeries& operator << (const QPointF &point);
    QXYSeries& operator << (const QList<QPointF> points);

    void setPen(const QPen& pen);
    QPen pen() const {return m_pen;}
    void setBrush(const QBrush& pen);
    QBrush brush() const {return m_brush;}

signals:
    void updated();
    void pointReplaced(int index);
    void pointRemoved(int index);
    void pointAdded(int index);

protected:
    QVector<qreal> m_x;
    QVector<qreal> m_y;
    QPen m_pen;
    QBrush m_brush;
};

QTCOMMERCIALCHART_END_NAMESPACE

#endif