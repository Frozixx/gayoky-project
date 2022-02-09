/*#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>   // pour les images 
#include<SDL/SDL_mixer.h>   //pour le son
#include<SDL/SDL_ttf.h> //pour les textes*/
#include "fct.h"  
int main(void)
{

SDL_Surface *screen=NULL,*image=NULL,*texte=NULL, *bouton=NULL ,*mvg=NULL, *texte2=NULL, *texte3=NULL ,*texte4=NULL;                        //*bouton=NULL ;
SDL_Rect positionEcran,test,posperso,positionBouton1,positionTexte,positionBouton2,positionTexte2;   
SDL_Event event ;             //?
TTF_Font *police =NULL,*police2=NULL;
SDL_Color couleurNoire = {20, 30, 50};
SDL_Color couleurq = {255, 69, 60};
int i;

Mix_Music *music ;//construct mix_music pointer

int continuer=1;



SDL_Init(SDL_INIT_VIDEO); //initialisation video
TTF_Init();      //initialisation texte 
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Erreur : %s \n ", SDL_GetError() );
return 1;

}
screen=SDL_SetVideoMode(1400,600,32,SDL_DOUBLEBUF | SDL_HWSURFACE); //Create a window surface 
SDL_WM_SetCaption("GAYOKY Game",NULL);   //?

if(screen==NULL)
{
printf("Erreur : %s \n ",SDL_GetError() );
return 1;
}
//
image=IMG_Load("./ressources/image/image.jpg");//loading an image to dispaly 
bouton=IMG_Load("./ressources/image/bouton.png");
//.mvg=IMG_Load("mvg.png");

// partie son 
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

music = Mix_LoadMUS("./ressources/son/music.mp3") ; //loading the music 
Mix_PlayMusic(music,-1);


police=TTF_OpenFont("./ressources/ttf/textfont.ttf",80);   //Chargement de la police avec defintion de la taille

police2=TTF_OpenFont("./ressources/ttf/textfont.ttf",40);

texte=TTF_RenderText_Blended(police,"Bnj",couleurNoire);//ecriture du texte dans sdl_surface en mode blended 
texte2=TTF_RenderText_Blended(police,"Gayoky",couleurNoire);
texte3=TTF_RenderText_Blended(police,"1a5",couleurNoire);
texte4=TTF_RenderText_Blended(police,"gayoky game",couleurq);


/*--------------------son bref section ------------*/
Mix_Chunk* son;
//son=Mix_LoadWAV("boutonsund.mp3");
Mix_PlayChannel(-1,son,0);




posperso.x=0;
posperso.y=0;
SDL_BlitSurface(mvg,NULL,screen,&posperso); 
SDL_Flip(screen);


while(continuer) 
{

test.x=0;   //avec le mvt du bouton
test.y=0;


positionEcran.x=0;
positionEcran.y=0;
SDL_BlitSurface(image,NULL,screen,&positionEcran);   /*blit du fond*/

positionBouton1.x=525;
positionBouton1.y=20;
SDL_BlitSurface(bouton,NULL,screen,&positionBouton1);   /*premier bouton*/

positionTexte.x=630;
positionTexte.y=135;
SDL_BlitSurface(texte,NULL,screen,&positionTexte); //blit du texte 


positionBouton2.x=525;
positionBouton2.y=250;
SDL_BlitSurface(bouton,NULL,screen,&positionBouton2);   /*deuxieme bouton */


positionEcran.x=800;
positionEcran.y=150;
SDL_BlitSurface(bouton,NULL,screen,&positionEcran);   /*3eme bouton*/

positionTexte.x=930;
positionTexte.y=260;
SDL_BlitSurface(texte3,NULL,screen,&positionTexte); //blit du texte  3



positionTexte.x=200;
positionTexte.y=260;
SDL_BlitSurface(texte4,NULL,screen,&positionTexte); //blit du texte  3



/*for(i=0;i<254;i+=5)             ce segment la est pour le mouvement du bouton en background
{
positionEcran.x+=5;
positionEcran.y=280;
SDL_BlitSurface(image,NULL,screen,&test); 
SDL_BlitSurface(bouton,NULL,screen,&positionEcran);   //deuxieme bouton 
SDL_Flip(screen);
SDL_Delay(800);
}*/



positionTexte2.x=630;
positionTexte2.y=365;
SDL_BlitSurface(texte2,NULL,screen,&positionTexte2);     //deuxieme texte



// Pour la fermeture de la fenetre
SDL_Event event;
SDL_WaitEvent(&event);
if(event.type==SDL_QUIT) {break;}
else if(event.type==SDL_KEYUP)
{
if(event.key.keysym.sym==SDLK_ESCAPE){break;}
if(event.key.keysym.sym==SDLK_RIGHT)                //pour le mvt a droite
{
posperso.x+=25;
SDL_BlitSurface(image,NULL,screen,&test);
 
SDL_BlitSurface(bouton,NULL,screen,&positionBouton2);
SDL_BlitSurface(texte,NULL,screen,&positionTexte); 
SDL_BlitSurface(bouton,NULL,screen,&positionBouton1);
SDL_BlitSurface(image,NULL,screen,&positionEcran); 

SDL_BlitSurface(mvg,NULL,screen,&posperso);   //deuxieme bouton 

SDL_Flip(screen);


}
if(event.key.keysym.sym==SDLK_DOWN)                       //why is there no difference between the two methods
{
posperso.y+=15;
SDL_BlitSurface(image,NULL,screen,&test); 
SDL_BlitSurface(mvg,NULL,screen,&posperso);   //deuxieme bouton 

SDL_Flip(screen);


}
if(event.key.keysym.sym==SDLK_UP)                     
{
posperso.y-=15;
SDL_BlitSurface(image,NULL,screen,&test); 
SDL_BlitSurface(mvg,NULL,screen,&posperso);   //deuxieme bouton 

SDL_Flip(screen);


}
if(event.key.keysym.sym==SDLK_LEFT)                     
{
posperso.x-=15;
SDL_BlitSurface(image,NULL,screen,&test); 
SDL_BlitSurface(mvg,NULL,screen,&posperso);   //deuxieme bouton 

SDL_Flip(screen);


}
}

SDL_Flip(screen);    //mettre a jour la fenetre


}


//mouseMove(SDL_MouseButtonEvent b,bouton,&image,positionEcran,screen);









TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte);
SDL_FreeSurface(texte2);
Mix_FreeMusic(music);
Mix_FreeChunk(son);

SDL_Quit();
return 0;
}
//aziz
