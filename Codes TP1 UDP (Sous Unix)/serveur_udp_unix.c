 #include <sys/types.h>
 #include <sys/socket.h>
 #include <stdio.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #define MAX_SIZE 128
 int main ()
{
 int dfs_serveur;
 int long_adr_serveur, long_adr_client;
 struct sockaddr_in adresse_serveur;
 struct sockaddr_in adresse_client;
 char buf[MAX_SIZE];
/*buff="ok"*/
 dfs_serveur = socket (AF_INET, SOCK_DGRAM, 0);
 if (dfs_serveur == -1)
 {
 perror ("socket");
 exit (1);
 }

 adresse_serveur.sin_family = AF_INET;
 inet_pton (AF_INET, "127.0.0.1", &adresse_serveur.sin_addr.s_addr);
 adresse_serveur.sin_port = htons (1234);

 long_adr_serveur = sizeof (adresse_serveur);
 if (bind(dfs_serveur, (struct sockaddr *) &adresse_serveur, long_adr_serveur) == -1)
 {
 perror ("bind error");
 exit (1);
 }

 while (1)
 {
 printf ("Attente de message\n");
 long_adr_client = sizeof (adresse_client);
 if (recvfrom (dfs_serveur, buf, MAX_SIZE, 0, (struct sockaddr *) &adresse_client, &long_adr_client)
== -1)
 {
 perror ("recvfrom");
 }

 printf ("%s\n", buf);
 printf ("%s\n", htons(adresse_client.sin_port));
 printf ("%s\n", inet_ntoa(adresse_client.sin_addr));
 }
 close (dfs_serveur);
  }
