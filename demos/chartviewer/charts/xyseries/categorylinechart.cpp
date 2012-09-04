/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include "charts.h"
#include "qchart.h"
#include "qlineseries.h"
#include <QCategoryAxis>

class CategoryLineChart: public Chart
{
public:
    QString name() { return QObject::tr("CategoryLineChart"); }
    QString category()  { return QObject::tr("XYSeries"); }
    QString subCategory() { return QString::null; }

    QChart* createChart(const DataTable& table) {

           QChart* chart = new QChart();
           chart->setTitle("Category Line chart");

           QString name("Series ");
           int nameIndex = 0;
           foreach (DataList list, table) {
               QLineSeries *series = new QLineSeries(chart);
               foreach (Data data, list)
                   series->append(data.first);
               series->setName(name + QString::number(nameIndex));
               nameIndex++;
               chart->addSeries(series);
           }

//           chart->createDefaultAxes();
           QCategoryAxis *axisX = new QCategoryAxis;
           axisX->append("low", 5);
           axisX->append("optimal", 12);
           axisX->append("high", 19);
           axisX->setRange(-1, 20);
           chart->setAxisX(axisX, chart->series().at(0));

           QCategoryAxis *axisY = new QCategoryAxis;
           axisY->append("low", 5);
           axisY->append("optimal", 8);
           axisY->append("high", 12);
           axisY->setRange(-5, 20);
           chart->setAxisY(axisY, chart->series().at(0));

           return chart;
    }

};

DECLARE_CHART(CategoryLineChart)
