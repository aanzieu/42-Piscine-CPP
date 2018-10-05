/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 10:06:43 by aanzieu           #+#    #+#             */
/*   Updated: 2018/10/03 15:36:00 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
// Functions Private
// --------------------
// Constructor
ZombieHorde::ZombieHorde(int n) :    amount(n) {
    
    if (n > 0) {
        this->horde = new Zombie[n];

        for (int i = 0; i < this->amount ; i++){
            this->horde[i].nameOfZombie_ = this->_randomName();
            this->horde[i].typeOfZombie_= "World War Z";
        }
    }
    return;
}

ZombieHorde::~ZombieHorde(void){
    delete [] this->horde;
    return;
}

// Functions Public
// -----------------------
// Return the amount of Zombies
int                 ZombieHorde::getAmountOfZombies(void) { return this->amount; }

void                ZombieHorde::announce_All_Zombies(void) const{
    for ( int i = 0; i < this->amount; i++)
    {
        this->horde[i].announce_Zombie_();
    }
}
// Functions Private
// -----------------------
// Return name random 
std::string         ZombieHorde::_randomName() { 
    return ZombieHorde::_namePool[(rand() % 180)];
}

// Variable Set
// --------------------
// all String for Zombies
std::string ZombieHorde::_namePool[180] = {
    "Brainy Allegheny",
    "Undead Jack Seizmore",
    "Bone Toothpick Juanita",
    "Missing Mandable Melvin",
    "Hiro the Gutless",
    "Rott Wilder",
    "‘Twas the Night Before Clement",
    "Club Foot",
    "No Feet",
    "Jasmine Boneforhands",
    "One Eyed William",
    "Mall Roaming Kevin Eubanks",
    "Mmrgh",
    "Mort A. Mortis",
    "Slim James",
    "No Tongue Hampton, The Silent Partner",
    "It’s not easy being Ed Greene",
    "Damn Flanders",
    "Cavity Chompsky",
    "Richard the Missing Hearted",
    "Carol Channing",
    "Fanger",
    "Foos",
    "Forever Calvin",
    "Obanyan Human Juice",
    "Cut ‘n’ Shoot Johnson",
    "Open Sole Shoemaker",
    "Meredith the Deaf",
    "Embalming Tyrone",
    "Run For the Hilliard",
    "Pitchfork Mob Joseph Mann",
    "Juan of the Seared Flesh",
    "The Stumbler",
    "Jacob’s Stepstool",
    "Underworld Ted",
    "Jacon Bloodless",
    "Dead Pirate Wesley",
    "Struwwelpeter",
    "Brain Daddy",
    "Skull Cracker Isaiah",
    "The Hungry One",
    "The Groaner",
    "Canon Fodder Johnny Eager",
    "Can’t Cheat at Cards Franklin No Eyes",
    "Frodo the Nine Fingered",
    "Graveyard Betty",
    "Resident Idle",
    "Vincent vanNoEars",
    "Harold Bitemark",
    "Holden in the Shadows",
    "The Late Gerald",
    "No More Lisa",
    "Gina Cadaverous",
    "Larry the Lifeless",
    "Unanimated Toby",
    "Jenna H., Dearly-Departed",
    "Louis K. Blooey",
    "Living Dead Fabulous",
    "Smells like J.B.",
    "Torn Shirt, the Howler",
    "Eye Socket Kate",
    "Doug Blue/Green",
    "Maggot and Phlegm Arin Rosetti",
    "Barney One-Shoe",
    "Still Dancing Hemphill",
    "Fashionably Late Cherisse, the Dress Ripper",
    "Dahmer’s Number Two Fan",
    "Hellspawn",
    "Limbo Pete, the Undead King",
    "Aimless Andrew Atkins",
    "Reanimated Marshall",
    "Too Late For Dinner Vijay",
    "Keith Richards",
    "Grey Matter Stew",
    "Crimson Stain Kanyon Wahl",
    "Punching Glass Elliot",
    "Jawbone",
    "Senor Toadstool",
    "No Skin No Pain Amanda",
    "Dirk Dirt Hands",
    "Slack and Drool, the Zombie Twins",
    "Gulletless the Scarce",
    "Almost-A-Ghost Gary",
    "Was Wilcox",
    "Returned to Sender",
    "Cracked Ribs Elwin, the Stiff Walker",
    "Putrified Half Nelson",
    "The Sound of Silas",
    "Bowel Powell",
    "Unknown Zombie",
    "Untold Horror",
    "Seymore Guts",
    "Halo of Flies, the Late Honorable Judge Carlsbad",
    "Moss Blanket",
    "Janet Coffin Splinter",
    "Rob",
    "Can’t take it with you Erik W.",
    "Mr. Dead",
    "Unlively Unlikely Unger",
    "Brain Pan Paul Birds Nest",
    "Timmy the Torso",
    "Re: Bob",
    "James Monroe",
    "Le Petit Mort",
    "Flannel Patch Odums",
    "Six Foot Underhill",
    "Jesus H. Christ",
    "Gene Grey",
    "Princess Eliza",
    "Hank the Wobble",
    "Entrails the Mighty",
    "Bloodshot the Near-zombie",
    "Naked and Famous Al",
    "Pontiac Empty Soul",
    "Aunt Festerly",
    "Ella Gently Wasted",
    "Smells Like A Spirit",
    "Eye-for-an-eye Hannibal",
    "Jimmy Hoffa",
    "Displaced Diana",
    "Heart on Sleeve Guts on Floor Evenrude",
    "Cement Shoes Arnie the Pivot",
    "The Bloat",
    "Mitch Hedberg",
    "Dark ‘n’ Twisty Jules",
    "Frankenstein’s Project 15C",
    "Hell-Hath-No-Fury-Like Kate",
    "Bernard the Wal-Mart Greeter",
    "Push Came to Shove Elias",
    "Samuel Butler, Forever Laughing",
    "Emily Dead-As-A-Post",
    "The Littlest Zombie",
    "Mindless Betty Wallkisser",
    "Driveshaft Ribcage Nick",
    "Shorty the Crawler",
    "Determined Zhi",
    "Dental Records Carmine Balderoni",
    "Officer Keith, Newly Risen",
    "Donald Eats-with-a-lisp",
    "The Wake Rider",
    "John Doe, the Toe Tag Collector",
    "Next of Kin Finn",
    "Herman Melville, ex nihilo",
    "Clairvius Narcisse",
    "Homo sapiens neandertalensis",
    "I.C. Fingers",
    "Clifford the Scientologist",
    "Stormtrooper number 16",
    "The Thriller",
    "Amelia Earhart",
    "Jakki Jowers, the Haitian",
    "St. Jimmy",
    "Optimus Prime",
    "Stormcrow",
    "8 Lives Gone Yusuf Islam",
    "Porridge Head",
    "Imogene Ashbaugh, the Skinned",
    "Nick Necroplis",
    "Ruth-less Pennebaker",
    "Creepy McCreep",
    "The Gaping Maw of Rick",
    "Is-hor, the Shadow-Soul",
    "Mors Venti",
    "Shiloh Lowry, Zombie Herder",
    "Coagulated McTavish",
    "Gruesome Gary Gopher-guts",
    "Diagenisis the Greek",
    "Ronin Death Rattle Esquire",
    "James Ossuary",
    "Sheol Shirker",
    "Bloodblister Bret",
    "Mummified Amisi, the Crossover",
    "Mob participant number 303",
    "Hell-less Les",
    "Olli the Draugr",
    "Zach, Mohrg Tsar",
    "Family Plot Eunice",
    "Bandaranaike The Redemption",
    "Clammy Hands Sophie",
    "Morris Kimmons, Cemetary Sitter",
};