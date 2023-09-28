/* PLANETS.C--Example from chapters 4 and 7 of User's Guide */

#include <graphics.h>           /* For graphics library functions */
#include <stdlib.h>             /* For exit() */
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int set_graph(void);            /* Initialize graphics */
void calc_coords(void);         /* Scale distances onscreen */
void draw_planets(void);        /* Draw and fill planet circles */

/* Draw one planet circle */
void draw_planet(float x_pos, float radius,
                 int color, int fill_style);
void get_key(void);         /* Display text on graphics screen, */
                            /* wait for key */

/* Global variables -- set by calc_coords() */
int max_x, max_y;           /* Maximum x- and y-coordinates */
int y_org;                  /* Y-coordinate for all drawings */
int au1;                    /* One astronomical unit in pixels
                               (inner planets) */
int au2;                    /* One astronomical unit in pixels
                               (outer planets) */
int erad;                   /* One earth radius in pixels */

int main()
{
   /* Exit if not EGA or VGA */
   /* Find out if they have what it takes */
   if (set_graph() != 1) {
      printf("This program requires EGA or VGA graphics\n");
      exit(0);
   }
   calc_coords();       /* Scale to graphics resolution in use */
   draw_planets();      /* Sun through Uranus (no room for others) */
   get_key();           /* Display message and wait for key press */
   closegraph();        /* Close graphics system */

   return 0;
}

int set_graph(void)
{
   int graphdriver = DETECT, graphmode, error_code;

   /* Initialize graphics system; must be EGA or VGA */
   initgraph(&graphdriver, &graphmode, "..\\bgi");
   error_code = graphresult();
   if (error_code != grOk)
      return(-1);               /* No graphics hardware found */
   if ((graphdriver != EGA) && (graphdriver != VGA))
   {
      closegraph();
      return 0;
   }
   return(1);                   /* Graphics OK, so return "true" */
}

void calc_coords(void)
{
   /* Set global variables for drawing */
   max_x = getmaxx();           /* Returns maximum x-coordinate */
   max_y = getmaxy();           /* Returns maximum y-coordinate */
   y_org = max_y / 2;           /* Set Y coord for all objects */
   erad = max_x  / 200;         /* One earth radius in pixels */
   au1 = erad * 39;             /* Scale for inner planets */
   au2 = erad * 10;             /* scale for outer planets */
}

void draw_planets()
{
 int i;
    i=0,2;
   draw_planet(9.2 * au2, 11.2 * erad, EGA_YELLOW, LINE_FILL);
   // Sol
   textbackground(0);
   while(i<=18){
   textbackground(0);
   draw_planet(9.2 * au2, 11.2 * erad, EGA_YELLOW, LINE_FILL);
   delay(1000);
   textbackground(0);
   draw_planet(i * au2, 10.4 * erad, EGA_BLUE, LINE_FILL);textbackground(0);
   // Luna
   i++;clrscr();textbackground(0);
   }
   textbackground(0);
   draw_planet(9.2 * au2, 11.2 * erad, EGA_YELLOW, LINE_FILL);
   draw_planet(39.2 * au2, 9.2 * erad, EGA_GREEN, LINE_FILL);
   draw_planet(18.2 * au2, 10.4 * erad, EGA_BLUE, LINE_FILL);
}

void draw_planet(float x_pos, float radius, int color, int fill_style)
{
   setcolor (color);
   circle(x_pos, y_org, radius);
   setfillstyle(fill_style, color);
   floodfill(x_pos, y_org, color);
}

void get_key(void)
{
   outtextxy(50, max_y - 20, "Presione enter ");
   outtextxy(120, max_y - 410, "eclipse solar");
   outtextxy(220, max_y - 10, "WWW.UBA_SOFTWARE.COM ");
   getch();
}
