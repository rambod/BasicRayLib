#include "raylib.h"
#include <cstdio>

int main()
{
    // window dimensions
    int width{800};
    int height{350};


    InitWindow(width,height, "Axe Game");
    // circle coordinate
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    //circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    bool collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (r_axe_x >= l_circle_x) && (l_axe_x <= r_circle_x);

    SetTargetFPS(60);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        if(collision_with_axe){
            DrawText("Game Over",400,200,50,RED);
        }
        else{
            //Game Logic

            // update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            //update coolistion with axe
            collision_with_axe = (b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (r_axe_x >= l_circle_x) && (l_axe_x <= r_circle_x);

             DrawCircle(circle_x,circle_y,circle_radius , BLUE);
                DrawRectangle(axe_x,axe_y,axe_length,axe_length,RED);
                axe_y += direction; 
                  if(axe_y > height|| axe_y < 0){
        direction = -direction;
    }
        if(IsKeyDown(KEY_D) && circle_x < width - circle_radius){
            circle_x += 10;
        }
            if(IsKeyDown(KEY_A) && circle_x > 0+circle_radius){
            circle_x -= 10;
        }
        if(IsKeyDown(KEY_S) && circle_y < height -circle_radius){
            circle_y += 10;
        }
            if(IsKeyDown(KEY_W) && circle_y > 0+circle_radius){
            circle_y -= 10;
        }

        }
       
  



        EndDrawing();
    }

}