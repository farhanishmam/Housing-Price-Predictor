#include <graphics.h>
#include <math.h>
#include "train.h"
#include<windows.h>

#define feature 1
#define G GREEN
#define X_AXIS  2
#define Y_AXIS  9000



void draw_last(float direction, double m, double c)
{
    double x = 0, y, px, py, cx = getmaxx()/2, cy = getmaxy()/2;

    while (x <= X_AXIS && x >= -X_AXIS)
    {
        /* Calculate y with given x */
        y = m*x + c;

        /* Calculate coordoninates to display */
        px = x * cx / X_AXIS + cx;
        /* -cy because of origin point in window(top left corner) */
        py = y * -cy / Y_AXIS + cy;
        /* in case boundaries are passed */
        if (py < 0 || py > getmaxy())
            break;

        if (x == 0) // only for first loop
            moveto(px, py);
        /* Draw segment line */
        lineto(px, py);
        /* update CP */
        moveto(px, py);

        x += direction;
        //delay(20);
    }
}

int implement(double a, double b)
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, NULL);

    /* Draw the axis */
    int cx = getmaxx()/2, cy = getmaxy()/2;

    line(20, cy, getmaxx()-20, cy);
    line(cx, 20, cx, getmaxy()-20);
    outtextxy(cx, cy, "O");
    outtextxy(20, cy, "-2000");
    outtextxy(getmaxx()-35, cy, "2000");
    outtextxy(cx, 20, "9 mil");
    outtextxy(cx, getmaxy()-20, "-9 mil");

    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 0, 2);

    /* from x=0 ++ */
    draw_last(0.01,a,b);
    /* from x=0 -- */
    //draw_last(-0.01);

    delay(5000);
    closegraph();
    return (0);
}



int int_face()
{
    int n;
    system("color 30");
    for(int i=0; i<10; i++)
        printf("\n");

    printf("                      ");
    printf("Welcome to the Housing Price Predictor");
    delay(1500);

start:

    system("cls");
    for(int i=0; i<8; i++)
        printf("\n");

    printf("                      ");
    printf("Please Enter Your Choice:\n\n");
    printf("                      ");
    printf("1)Predict Price\n");
    printf("                      ");
    printf("2)Provide Data\n");
    printf("                      ");
    printf("3)Exit\n\n");
    printf("                      ");
    scanf("%d",&n);

    if(n == 1)
    {
        system("color 30");
        system("cls");
        for(int i=0; i<8; i++)
            printf("\n");

        printf("                      ");
        printf("Enter the area of the house(sq. ft): ");

        double area;
        scanf("%lf",&area);
        getchar();

        double c, m;
        FILE *f = fopen("Theta.txt", "r");
        fscanf(f, "%lf", &c);
        fscanf(f, "%lf", &m);
        fclose(f);

        system("cls");
        system("color 30");

        for(int i=0; i<8; i++)
            printf("\n");

        printf("                      ");
        printf("The price is %0.2f\n\n\n", c + m*area);
        printf("                      ");
        printf("Press Enter To Continue");
        getchar();
    }

    else if(n == 2)
    {
        system("color 30");
        system("cls");
        for(int i=0; i<8; i++)
            printf("\n");

        printf("         ");
        printf("Enter the number of data you want to provide:\n");
        printf("         ");

        int k, i;
        scanf("%d",&k);

        system("color 30");
        system("cls");

        printf("\n\n\n         ");
        printf("Enter the area of the house first and then the price.\n");
        printf("         ");
        printf("Both inputs should be separated by a space\n\n\n");

        int isempty = 0;
        FILE *f = fopen("data.txt", "r");
        if(fgetc(f) == EOF)
            isempty = 1;

        fclose(f);

        f = fopen("data.txt", "a");
        double a, b;
        for(i=0; i<k; i++)
        {
            printf("         ");
            scanf("%lf %lf", &a, &b);

            if(isempty == 1 && i == 0)
                fprintf(f, "%f %f", a, b);
            else
                fprintf(f, "\n%f %f", a, b);
        }
        getchar();
        fclose(f);

        printf("\n         ");
        printf("Training Data . . .");
        train(feature);
        printf("\n         ");
        printf("Data is trained");
        printf("\n\n                        ");
        printf("Press Enter To Visualize Data");
        getchar();

        double c, m;
        f = fopen("Theta.txt", "r");
        fscanf(f, "%lf", &c);
        fscanf(f, "%lf", &m);
        fclose(f);

        implement(m, c);
        printf("\n\n                        ");
        printf("Press Enter To Continue");
        getchar();
    }
    else if(n==3)
    {
        for(int i=0; i<8; i++)
            printf("\n");

        printf("                      ");
        system("cls");

        for(int i=0; i<8; i++)
            printf("\n");

        printf("                      ");
        printf("Are you sure you want to exit?\n\n");
        printf("                      ");
        printf("(Y)es or (N)o?\n");
        printf("\n                      ");

        char k;
        getchar();
        scanf("%c",&k);

        if((k=='Y')||(k=='y'))
            exit(1);
    }

    goto start;
}
