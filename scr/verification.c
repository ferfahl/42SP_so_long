/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves < feralves@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/14 00:59:15 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

//read a file
    //check file to turn into map (.ber)

    //maps verifications
    /*"if any misconfiguration of any kind is encountered in the file, the
	program must exit in a clean way, and return "Error\n" followed by an 
    explicit error message of your choice."
        //empty map
        //not expected characters
        //there can only be 1 player
            //if theres more?
        //not retangular
        //no collectible
        //at least 1 exit
        //valid extension
        //valid dimension
        //surrounded by walls
        //"valid path"

// generate map archive
    //verify all positions
    //Verificar os botões (- e v) para não permitir que o jogo feche

//in-game verifications
    //mover personagem usando WASD (minusculas?)
    //have two counters -> players movement and collected objs
        //A cada movimento, incrementa count_movs;
        //mostrar no terminal/na tela o count_movs atualizado
    //player's position
    //can it move? (restringir a direção do movimento)
    //next block is a wall -> what happens?
        //if (is_parede) nada acontece; else se move na direção
    //next block is a collectible -> what happens?
        //collectible must disapear and the counter go one up
        //atualizar o count_item quando o personagem pegar o colecionável
        //Se personagem pegar o colecionável, saída muda para "aberta"
    //next block is the exit - > what happens?
        //if (count_collect < total_collect) nada acontece; else encerra o jogo













// BONUS
    //Make the player lose when they touch an enemy patrol
    //Add some sprite animation.
    //Display the movement count directly on screen instead of writing it in the shell.
