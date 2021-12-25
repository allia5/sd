 #include <sys/types.h>
 #include <sys/socket.h>
 #include <stdio.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 #define n 7
 int main ()
 {
 int dfs_client;
 int len;
 char buff[1024];
 struct sockaddr_in adresse_serveur;
 int result;

 dfs_client = socket (AF_INET, SOCK_STREAM, 0);

 adresse_serveur.sin_family = AF_INET;
 adresse_serveur.sin_addr.s_addr = inet_addr ("127.0.0.1");
 adresse_serveur.sin_port = htons (1234);
 len = sizeof (adresse_serveur);

 result = connect (dfs_client, (struct sockaddr *) &adresse_serveur, len);
 if (result == -1)
 {
 perror ("Erreur de connexion au serveur");
 exit (1);
 }
 
 
 

    int tab[] = {1, 12, 3, 3, 300, 5, 3};

    printf("Envoie tab\n");
    for(int i = 0; i < n; i++){
        printf("%d  ", tab[i]);       
    }
    /*
    s="";
    printf("seiser text or quitter pour exit");
    scanf("%s",&text);
    
    */



    if(send(dfs_client, /*s*/tab, sizeof tab, 0) < 0)    
    {
        printf("\nTab non envoyé\n");
    }
    else
    {
        printf("\ntab envoyé\n");
    }
   /*  recv(dfs_client,text, sizeof text tabReceived, 0));*/

    printf("\n");
    
    
        
 close (dfs_client);
 exit (0);
 
 }
 
 
 
