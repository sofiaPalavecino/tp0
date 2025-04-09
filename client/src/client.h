#ifndef CLIENT_H_
#define CLIENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include "utils.h"


t_log* iniciar_logger(void);
t_config* iniciar_config(void);
char *obtener_valor(t_config*, char*);
void leer_consola(t_log*);
void input_consola_a_paquete(t_log*, t_paquete*);
void paquete(int, t_log*);
void terminar_programa(int, t_log*, t_config*);

#endif /* CLIENT_H_ */
