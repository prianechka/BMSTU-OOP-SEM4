#include "draw.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "defines.h"
#include "object.h"

static void create_scene(const int w, const int h, struct Draw dr)
{
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(-w / 2, -h / 2, w - 2, h - 2);
    dr.QGV->setScene(scene);
}

// Создать структуру и поместить туда qpen
static QPen create_pen()
{
    QPen penBlack(COLOR);
    return penBlack;
}

static void add_line(struct Draw dr, const line_t line, const QPen pen)
{
    dr.QGV->scene()->addLine(line.x_1, line.y_1, line.x_2, line.y_2, pen);
}

int draw_object(object_t &object, struct Draw dr)
{
    create_scene(dr.w, dr.h, dr);
    QPen pen = create_pen();
    points_t points = object.object_points;
    lines_t lines = object.object_lines;
    for (int i = 0; i < lines.count_lines; i++)
    {
        line_t line;
        int ind_p1 = lines.array[i].p_1;
        int ind_p2 = lines.array[i].p_2;
        line.x_1 = points.array[ind_p1].x;
        line.y_1 = points.array[ind_p1].y;
        line.x_2 = points.array[ind_p2].x;
        line.y_2 = points.array[ind_p2].y;
        add_line(dr, line, pen);
    }
    return OK;
}
