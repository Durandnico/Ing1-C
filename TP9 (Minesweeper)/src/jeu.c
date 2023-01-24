/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 07/01/2023 02:21:39 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file jeu.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 02:21:39
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/minesweeper.h"


int
rand_int(int int_target)
{     
    float flt_tmp = (float) rand()/RAND_MAX;

    /*To make even the chance to get target*/
    if(flt_tmp == 1)
        flt_tmp -= 0.01;
    
    return (int) (flt_tmp * ++int_target);
}


void
generate_bombe(t_recup* ptr_rcp_recup, int int_x, int int_y)
{
    int int_xb;     //x pos of the bombe
    int int_yb;     //y pos of the bombe
    int int_count;  //bombe count
    int i;          //loop variable
    int j;          //loop variable
    int int_R_edge; //check if on the edge of the board
    int int_B_edge; //check if on the edge of the board
   
    int_count = ptr_rcp_recup->int_bombe;
    
    while(int_count > 0)
    {
        int_xb = rand_int(ptr_rcp_recup->int_window_width - 1);
        int_yb = rand_int(ptr_rcp_recup->int_window_height - 1);

        /*if not close to the first click and not bomb, set as bomb*/
        if(ptr_rcp_recup->pptr_btn_board[int_yb][int_xb].int_isBombe == 0 && ((int_xb < int_x - 1 || int_xb > int_x + 1) || (int_yb < int_y - 1 || int_yb > int_y + 1)))
        {
           ptr_rcp_recup->pptr_btn_board[int_yb][int_xb].int_isBombe = 1;
            --int_count;
            
            int_R_edge = (int_xb == ptr_rcp_recup->int_window_width - 1) ? 1 : 2; 
            int_B_edge = (int_yb == ptr_rcp_recup->int_window_height - 1) ? 1 : 2;
            
            for( i = (int_xb == 0) ? 0 : -1; i < int_R_edge; i++)
                for(j = (int_yb == 0) ? 0 : -1; j < int_B_edge; j++)
                    ptr_rcp_recup->pptr_btn_board[j + int_yb][i + int_xb].int_neighbor++;
        }
    }
}



int
case_clicked(int keycode, int int_x, int int_y, void* ptr_void_recup)
{   
    static int sint_first = 0;
    t_recup* ptr_rcp_recup = (t_recup*) ptr_void_recup;
    int int_res;    //return variable set to 0

    int_res = 0;

    if(sint_first == 0){
        srand(time(NULL));
        generate_bombe(ptr_rcp_recup, int_x, int_y);
        sint_first = 1;
    }     

    if(keycode == 1)
        int_res = (reveal(ptr_rcp_recup, int_x, int_y));

    if(keycode == 3)
        ptr_rcp_recup->pptr_btn_board[int_y][int_x].int_flaged = !ptr_rcp_recup->pptr_btn_board[int_y][int_x].int_flaged; 

    show_everything(ptr_rcp_recup);

    if(int_res == 1)
        end(ptr_rcp_recup, 0);
    
    return (int_res);
}


int reveal(t_recup* ptr_rcp_recup, int int_x, int int_y)
{
    int i;              //loop variable
    int j;              //loop variable
    int int_R_edge;     //if we are on the Right border
    int int_B_edge;     //if we are on the Botton border
    static int sint_count = 0;

    /*if already showed or flag, do nothing*/
    if(ptr_rcp_recup->pptr_btn_board[int_y][int_x].int_state == 1 || ptr_rcp_recup->pptr_btn_board[int_y][int_x].int_flaged)
        return 0;

    /*if bomb, show and return*/
    if(ptr_rcp_recup->pptr_btn_board[int_y][int_x].int_isBombe)
        return 1;

    /*reveal case*/
    ptr_rcp_recup->pptr_btn_board[int_y][int_x].int_state = 1;
    change_button_image(&ptr_rcp_recup->pptr_btn_board[int_y][int_x], get_correct_xpm(ptr_rcp_recup, ptr_rcp_recup->pptr_btn_board[int_y][int_x]));
    
    /*1 good case as been reveal*/
    sint_count++;
    if(sint_count == ptr_rcp_recup->int_window_width * ptr_rcp_recup->int_window_height - ptr_rcp_recup->int_bombe){
        printf("it's a win !!\n");
        end(ptr_rcp_recup, 1);
        return 0;
    }

    /*if no bomb next : reveal neighbors*/
    if( ptr_rcp_recup->pptr_btn_board[int_y][int_x].int_neighbor == 0) {
        int_R_edge = (int_x == ptr_rcp_recup->int_window_width - 1) ? 1 : 2; 
        int_B_edge = (int_y == ptr_rcp_recup->int_window_height - 1) ? 1 : 2;

        for( i = (int_x == 0) ? 0 : -1; i < int_R_edge; i++)
            for(j = (int_y == 0) ? 0 : -1; j < int_B_edge; j++)
                reveal(ptr_rcp_recup, i + int_x, j + int_y);
    }
    return 0;
}


void end(t_recup* ptr_rcp_recup, int int_win)
{
    int i;  //loop variable
    int j;  //loop variable
    for(i = 0; i < ptr_rcp_recup->int_window_height; i++)
        for(j = 0; j < ptr_rcp_recup->int_window_width; j++){
            ptr_rcp_recup->pptr_btn_board[i][j].int_state   = 1;
            if(int_win == 0 && ptr_rcp_recup->pptr_btn_board[i][j].int_isBombe)
                change_button_image(&ptr_rcp_recup->pptr_btn_board[i][j], get_correct_xpm(ptr_rcp_recup, ptr_rcp_recup->pptr_btn_board[i][j]));
        }
    
    show_everything(ptr_rcp_recup);
}