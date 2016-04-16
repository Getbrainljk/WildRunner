#include "Images.hpp"

Images::Images(void)
{
  menu = new msdl::Image;
  if (menu->init("Images/beatles.png") == false)
    exit(0);
  background = new msdl::Image;
  if (background->init("Images/background.png") == false)
    exit(0);
  win[0] = new msdl::Image;
  if (win[0]->init("Images/win.png") == false)
    exit(0);
  win[1] = new msdl::Image;
  if (win[1]->init("Images/win2.png") == false)
    exit(0);
  win[2] = new msdl::Image;
  if (win[2]->init("Images/win3.png") == false)
    exit(0);
  win[3] = new msdl::Image;
  if (win[3]->init("Images/win4.png") == false)
    exit(0);
  win[4] = new msdl::Image;
  if (win[4]->init("Images/win5.png") == false)
    exit(0);
  win[5] = new msdl::Image;
  if (win[5]->init("Images/win6.png") == false)
    exit(0);
  interface = new msdl::Image;
  if (interface->init("Images/controles.png") == false)
    exit(0);
  lumiere = new msdl::Image;
  if (lumiere->init("Images/lumiere.png") == false)
    exit(0);
  imageHuman = new msdl::Image;
  if (imageHuman->init("Images/Sprite_2D_kiki_marche.png") == false)
    exit(0);
  imageHumanJump = new msdl::Image;
  if (imageHumanJump->init("Images/Sprite_2D_kiki_saut.png") == false)
    exit(0);
  imageSouris = new msdl::Image;
  if (imageSouris->init("Images/Sprite_2D_souris_marche.png") == false)
    exit(0);
  imageSourisJump = new msdl::Image;
  if (imageSourisJump->init("Images/Sprite_2D_souris_saut.png") == false)
    exit(0);
  imageFelin = new msdl::Image;
  if (imageFelin->init("Images/Sprite_2D_felin_marche.png") == false)
    exit(0);
  imageFelinJump = new msdl::Image;
  if (imageFelinJump->init("Images/Sprite_2D_felin_saut.png") == false)
    exit(0);
  imageKangourou = new msdl::Image;
  if (imageKangourou->init("Images/Sprite_2D_kangourou_marche.png") == false)
    exit(0);
  imageKangourouJump = new msdl::Image;
  if (imageKangourouJump->init("Images/Sprite_2D_kangourou_saut.png") == false)
    exit(0);
  obstacle[Map::PYLONNE_1] = new msdl::Image;
  if (obstacle[Map::PYLONNE_1]->init("Images/pylone.png") == false)
    exit(0);
  obstacle[Map::PYLONNE_2] = new msdl::Image;
  if (obstacle[Map::PYLONNE_2]->init("Images/pylone_2.png") == false)
    exit(0);
  obstacle[Map::PYLONNE_3] = new msdl::Image;
  if (obstacle[Map::PYLONNE_3]->init("Images/pylone_3.png") == false)
    exit(0);
  obstacle[Map::WALL] = new msdl::Image;
  if (obstacle[Map::WALL]->init("Images/brique.png") == false)
    exit(0);
  obstacle[Map::ENTRE_TUBE] = new msdl::Image;
  if (obstacle[Map::ENTRE_TUBE]->init("Images/tunnel_entree.png") == false)
    exit(0);
  obstacle[Map::TUBE_MARRON] = new msdl::Image;
  if (obstacle[Map::TUBE_MARRON]->init("Images/interieur_marron_1.png") == false)
    exit(0);
  obstacle[Map::TUBE_MARRON2] = new msdl::Image;
  if (obstacle[Map::TUBE_MARRON2]->init("Images/interieur_marron_2.png") == false)
    exit(0);
  obstacle[Map::TUBE_VERT] = new msdl::Image;
  if (obstacle[Map::TUBE_VERT]->init("Images/interieur_vert_1.png") == false)
    exit(0);
  obstacle[Map::TUBE_VERT2] = new msdl::Image;
  if (obstacle[Map::TUBE_VERT2]->init("Images/interieur_vert_2.png") == false)
    exit(0);
  obstacle[Map::TUBE_BLEU] = new msdl::Image;
  if (obstacle[Map::TUBE_BLEU]->init("Images/interieur_bleu_1.png") == false)
    exit(0);
  obstacle[Map::TUBE_BLEU2] = new msdl::Image;
  if (obstacle[Map::TUBE_BLEU2]->init("Images/interieur_bleu_2.png") == false)
    exit(0);

  /*  porte[Map::PORTE_ROUGE - (Map::BEGIN_SPRITE + 1)] = new msdl::Image;
  if (porte[Map::PORTE_ROUGE - (Map::BEGIN_SPRITE + 1)]->init("Images/Decor_2D_porte_rouge.png") == false)
    exit(0);
  porte[Map::PORTE_BLEU - (Map::BEGIN_SPRITE + 1)] = new msdl::Image;
  if (porte[Map::PORTE_BLEU - (Map::BEGIN_SPRITE + 1)]->init("Images/Decor_2D_porte_bleu.png") == false)
    exit(0);
  */
  // liste sprites
  spriteLumiere = new msdl::Sprite(*lumiere, 3, 200, 200, 1000 / 15);
  spriteHuman = new msdl::Sprite(*imageHuman, 8, 50, 150, 1000 / 15);
  spriteHumanJump = new msdl::Sprite(*imageHumanJump, 8, 50, 150, 1000 / 15);
  spriteSouris = new msdl::Sprite(*imageSouris, 8, 50, 50, 1000 / 15);
  spriteSourisJump = new msdl::Sprite(*imageSourisJump, 8, 50, 50, 1000 / 15);
  spriteFelin = new msdl::Sprite(*imageFelin, 8, 100, 100, 1000 / 15);
  spriteFelinJump = new msdl::Sprite(*imageFelinJump, 10, 100, 100, 1000 / 15);
  spriteKangourou = new msdl::Sprite(*imageKangourou, 10, 100, 150, 1000 / 15);
  spriteKangourouJump = new msdl::Sprite(*imageKangourouJump, 8, 100, 150, 1000 / 15);

  spriteKangourouJump = new msdl::Sprite(*imageKangourouJump, 8, 100, 150, 1000 / 15);
  spriteKangourouJump = new msdl::Sprite(*imageKangourouJump, 8, 100, 150, 1000 / 15);

  //  spritePorte[Map::PORTE_ROUGE - (Map::BEGIN_SPRITE + 1)] = new msdl::Sprite(*porte[Map::PORTE_ROUGE - (Map::BEGIN_SPRITE + 1)], 8, 100, 150, 1000 / 15);
  //spritePorte[Map::PORTE_BLEU - (Map::BEGIN_SPRITE + 1)] = new msdl::Sprite(*porte[Map::PORTE_BLEU - (Map::BEGIN_SPRITE + 1)], 8, 100, 150, 1000 / 15);
}

Images::~Images(void)
{
  delete menu;
  delete background;
  for (unsigned short i = 0; i < 6; ++i)
    delete win[i];
  delete interface;
  delete lumiere;
  delete imageHuman;
  delete imageHumanJump;
  delete imageSouris;
  delete imageSourisJump;
  delete imageFelin;
  delete imageFelinJump;
  delete imageKangourou;
  delete imageKangourouJump;
  delete spriteLumiere;
  delete spriteHuman;
  delete spriteHumanJump;
  delete spriteSouris;
  delete spriteSourisJump;
  delete spriteFelin;
  delete spriteFelinJump;
  delete spriteKangourou;
  delete spriteKangourouJump;
}
