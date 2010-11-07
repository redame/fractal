/* Author: Vladimir Belikov
 *
 * This file is part of Fractal Library.
 *
 * Fractal Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Fractal Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Fractal Libray.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FLGRAPHICSVIEW_H
#define FLGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>

class FLGraphicsView: public QGraphicsView
{
    Q_OBJECT
public:
    FLGraphicsView(QWidget *parent = 0) : QGraphicsView(parent) {}
signals:
    void resize(QSize size);
protected:
    virtual void resizeEvent(QResizeEvent *event)
    {
        QGraphicsView::resizeEvent(event);
        emit resize(event->size());
    }
};

#endif // FLGRAPHICSVIEW_H
