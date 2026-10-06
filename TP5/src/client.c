/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];

  memset(data, 0, sizeof(data));

  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);

  strcpy(data, "message: ");
  strcat(data, message);

  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  memset(data, 0, sizeof(data));

  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  printf("Message reçu: %s\n", data);

  return 0;
}

/**
 * Envoie une opération de calcul au serveur.
 */
int envoie_operateur_numeros(int socketfd)
{
  char operateur;
  double nombre1;
  double nombre2;
  char data[1024];

  printf("Entrez l'opérateur (+, -, *, /) : ");
  scanf(" %c", &operateur);

  printf("Entrez le premier nombre : ");
  scanf("%lf", &nombre1);

  printf("Entrez le deuxième nombre : ");
  scanf("%lf", &nombre2);

  snprintf(data, sizeof(data), "calcule : %c %.2f %.2f",
           operateur, nombre1, nombre2);

  if (write(socketfd, data, strlen(data)) < 0)
  {
    perror("Erreur d'écriture");
    return -1;
  }

  memset(data, 0, sizeof(data));

  if (read(socketfd, data, sizeof(data)) < 0)
  {
    perror("Erreur de lecture");
    return -1;
  }

  printf("%s\n", data);

  return 0;
}

int main()
{
  int socketfd;

  struct sockaddr_in server_addr;

  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  int connect_status = connect(socketfd,
                               (struct sockaddr *)&server_addr,
                               sizeof(server_addr));

  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    envoie_operateur_numeros(socketfd);
  }

  close(socketfd);

  return 0;
}
