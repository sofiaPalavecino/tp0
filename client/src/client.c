#include "client.h"
#include <readline/readline.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	log_info(logger, "Hola! Soy un log");


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	ip = obtener_valor(config, "IP");
	puerto = obtener_valor(config, "PUERTO");
	valor = obtener_valor(config, "CLAVE");

	// Loggeamos el valor de config

	log_info(logger, "IP: %s", ip);
	log_info(logger, "PUERTO: %s", puerto);
	log_info(logger, "CLAVE: %s", valor);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	//conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	//paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create("cliente_log.log", "LOGGER_CLIENTE", 1, LOG_LEVEL_INFO);

	if(nuevo_logger == NULL) {
		perror("Error creando el logger");
		exit(EXIT_FAILURE);
	}

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create("cliente.config");

	if(nuevo_config == NULL) {
		perror("Error al intentar cargar el config");
		exit(EXIT_FAILURE);
	}

	return nuevo_config;
}

char *obtener_valor(t_config *config, char *key) 
{
	if (!config_has_property(config, key)) {
		perror("Error obteniendo valor: key inexistente");
		exit(EXIT_FAILURE);
	} 
	
	return config_get_string_value(config, key);
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío

	while (1){
		leido = readline("> ");

		if(!leido || *leido == '\0') {
			break;
		}

		log_info(logger, "%s\n", leido);
		free(leido);
	}

	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	  log_destroy(logger);
	  config_destroy(config);
}
