#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <errno.h>

// global variables
int circle_points = 0;
float pi;

double random_double()
{
        return random() / ((double)RAND_MAX + 1);
}

int count_points(int npoints)
{
        int hit_count = 0;
        double x, y = 0.0;
        // Check for points inside circle
        for (int i = 0; i < npoints; i++)
        {
                /* generate random numbers between -1.0 and +1.0 (exclusive) */
                x = random_double() * 2.0 - 1.0;
                y = random_double() * 2.0 - 1.0;
                if (sqrt(x * x + y * y) < 1.0)
                        ++hit_count;
        }
        return hit_count;
}

// float calc_pi(int npoints)
// {
//         printf("calcpi npoints = %i\n", npoints);
//         printf("calcpi PI ratio: %d\n", (4.00 * circle_points) / npoints);
//         return (float)(4.00 * circle_points) / npoints;
// }

void *calc_pi(void *param)
{
        int npoints = *((int *)param);
        printf("calcpi npoints = %i\n", npoints);
        printf("calcpi PI ratio: %d\n", (4.00 * circle_points) / npoints);
        pi = (float)(4.00 * circle_points) / npoints;
}

void *calc_npoints(void *param)
{
        int points = *((int *)param);
        printf("runner npoints = %i\n", points);
        double x, y = 0.0;
        // Check for points inside circle
        circle_points = count_points(points);
        printf("runner circle points = %i\n", circle_points);
        // float hit_ratio = (4.00 * hit_count) / npoints;
        pthread_exit(0);
}

int main(int argc, char *argv[])
{
        // user must provide 2 console arguments when running program
        if (argc != 2)
        {
                printf("Error: An incorrect number of arguments was provided.\nPlease provide the total number of points.");
                exit(EXIT_FAILURE);
        }
        // vars
        pthread_t tID;       // thread 1 id
        pthread_t tID2;      // thread 2 id
        pthread_attr_t attr; // thread attributes (NULL)
        int npoints;         // total number of points (provided as an arg from the user)

        npoints = atoi(argv[1]); // convert str to int

        // user cannot say there are 0 total points.
        if (npoints == 0)
        {
                printf("Error: An incorrect number of arguments was provided.\nPlease provide the total number of points that is not 0.");
                exit(EXIT_FAILURE);
        }

        //  create a thread, execute calc_npoints method
        pthread_create(&tID, 0, calc_npoints, &npoints);
        pthread_join(tID, NULL);
        //  create a thread, execute calc_pi method
        pthread_create(&tID2, 0, calc_pi, &npoints);
        pthread_join(tID2, NULL);

        printf("main npoints = %i\n", npoints);
        printf("main circle points = %i\n", circle_points);
        printf("main Pi ratio: %f\n", pi);

        exit(EXIT_SUCCESS);
}