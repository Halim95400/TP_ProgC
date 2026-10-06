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
 * Envoie une opération au serveur et récupère le résultat.
 */
int envoyer_calcul(int socketfd, char operateur, double nombre1, double nombre2, double *resultat)
{
    char data[1024];

    snprintf(data, sizeof(data),
             "calcule : %c %.2f %.2f",
             operateur, nombre1, nombre2);

    if (write(socketfd, data, strlen(data)) < 0)
    {
        perror("Erreur d'écriture");
        return -1;
    }

    memset(data, 0, sizeof(data));

    int read_status = read(socketfd, data, sizeof(data) - 1);

    if (read_status < 0)
    {
        perror("Erreur de lecture");
        return -1;
    }

    data[read_status] = '\0';

    if (sscanf(data, "calcule : %lf", resultat) != 1)
    {
        printf("Réponse du serveur : %s\n", data);
        return -1;
    }

    printf("%s\n", data);

    return 0;
}

int main()
{
    int socketfd;
    struct sockaddr_in server_addr;

    double notes[5];
    double somme1;
    double somme2;
    double somme_totale;
    double moyenne;

    /*
     * Lecture du fichier des étudiants.
     */
    FILE *fichier = fopen("../../TP4/src/etudiant.txt", "r");

    if (fichier == NULL)
    {
        perror("Impossible d'ouvrir etudiant.txt");
        return EXIT_FAILURE;
    }

    char nom[50];
    char prenom[50];
    int age;

    for (int i = 0; i < 5; i++)
    {
        if (fscanf(fichier, "%49s %49s %d %lf",
                   nom, prenom, &age, &notes[i]) != 4)
        {
            printf("Erreur de lecture de l'étudiant %d.\n", i + 1);
            fclose(fichier);
            return EXIT_FAILURE;
        }

        printf("Étudiant %d : %s %s - note %.2f\n",
               i + 1, nom, prenom, notes[i]);
    }

    fclose(fichier);

    /*
     * Création de la socket.
     */
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if (socketfd < 0)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    /*
     * Connexion au serveur.
     */
    if (connect(socketfd,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0)
    {
        perror("connection serveur");
        close(socketfd);
        return EXIT_FAILURE;
    }

    /*
     * Note 1 + Note 2
     */
    if (envoyer_calcul(socketfd, '+', notes[0], notes[1], &somme1) < 0)
    {
        close(socketfd);
        return EXIT_FAILURE;
    }

    /*
     * Note 3 + Note 4
     */
    if (envoyer_calcul(socketfd, '+', notes[2], notes[3], &somme2) < 0)
    {
        close(socketfd);
        return EXIT_FAILURE;
    }

    /*
     * Somme des deux premiers résultats.
     */
    if (envoyer_calcul(socketfd, '+', somme1, somme2, &somme_totale) < 0)
    {
        close(socketfd);
        return EXIT_FAILURE;
    }

    /*
     * Ajout de la cinquième note.
     */
    if (envoyer_calcul(socketfd, '+', somme_totale, notes[4], &somme_totale) < 0)
    {
        close(socketfd);
        return EXIT_FAILURE;
    }

    /*
     * Moyenne des 5 étudiants.
     */
    if (envoyer_calcul(socketfd, '/', somme_totale, 5, &moyenne) < 0)
    {
        close(socketfd);
        return EXIT_FAILURE;
    }

    printf("\nSomme totale : %.2f\n", somme_totale);
    printf("Moyenne de la classe : %.2f\n", moyenne);

    close(socketfd);

    return 0;
}