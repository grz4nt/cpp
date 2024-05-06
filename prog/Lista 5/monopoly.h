#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <string>
#include <vector>

class Player {
    std::string name;
    int money;
    int position;
    bool inJail; // Whether the player is in jail
    std::vector<Property*> properties; // Properties owned by the player
    bool hasGetOutOfJailFreeCard; // Whether the player has a "Get out of jail free" card
    int numRailroadsOwned; // Number of railroads owned by the player
    int numUtilitiesOwned; // Number of utilities owned by the player   
    int numHouses; // Number of houses owned by the player 
    int numHotels; // Number of hotels owned by the player
    void move(int steps); // Move the player by a certain number of steps
};
class Property {
    std::string name;
    int cost;
    int rent;
    Player* owner;
    bool mortgaged; // Whether the property is mortgaged
    int numHouses; // Number of houses built on the property
    int numHotels; // Number of hotels built on the property
    bool isMonopoly; // Whether the player owns all properties of the same color group
    int mortgageValue; // Value of the property when mortgaged
    int houseCost; // Cost to build a house on the property
    int hotelCost; // Cost to build a hotel on the property
};
class Board {
    std::vector<Property*> properties;
    std::vector<Player*> players; // Players in the game
    std::vector<ChanceCard*> chanceCards; // Chance cards in the game
    std::vector<CommunityChestCard*> communityChestCards; // Community chest cards in the game
    std::vector<Utility*> utilities; // Utilities in the game
    std::vector<Railroad*> railroads; // Railroads in the game
    FreeParking* freeParking; // The "Free Parking" space in the game
    ChanceCard* chance; // The "Chance" space in the game
    CommunityChestCard* communityChest; // The "Community Chest" space in the game
    std::vector<House*> houses; // Houses in the game
    std::vector<Hotel*> hotels; // Hotels in the game
};
class ChanceCard {
    std::string description;
    int effect; // The effect of the card (e.g., move forward 3 spaces, pay $200, etc.)
    bool isGetOutOfJailCard; // Whether the card is a "Get out of jail free" card
    bool isAdvanceToGoCard; // Whether the card is an "Advance to Go" card
    int moneyEffect; // The amount of money gained or lost by the player
    int moveEffect; // The number of spaces the player should move
};
class CommunityChestCard {
    std::string description;
    int effect; // The effect of the card
    bool isGetOutOfJailCard; // Whether the card is a "Get out of jail free" card
    bool isAdvanceToGoCard; // Whether the card is an "Advance to Go" card
    int moneyEffect; // The amount of money gained or lost by the player
    int moveEffect; // The number of spaces the player should move
    bool isCollectFromPlayersCard; // Whether the card allows the player to collect money from other players
    bool isPayToPlayersCard; // Whether the card requires the player to pay money to other players
};
class Dice {
    int sides;
    bool isRolled; // Whether the dice has been rolled
    int lastRoll; // The result of the last roll
    int moveSteps; // Number of steps to move the player
};
class Banker {
    int totalMoney;
    std::vector<Property*> properties;
    std::vector<Player*> players; // Players who have mortgaged properties
};
class Jail {
    int jailFee; // Fee to get out of jail
    std::vector<Player*> inmates; // Players currently in jail
};

class Utility {
    std::string name;
    int cost; // Cost to buy the utility
    Player* owner;
    int rent; // Rent to be paid by players who land here
};

class Railroad {
    std::string name;
    int cost; // Cost to buy the railroad
    Player* owner;
    int rent; // Rent to be paid by players who land here
};

class Tax {
    int taxAmount; // Amount of tax to be paid
    std::string taxName; // Name of the tax
};

class Go {
    int passMoney; // Money received by players when they pass Go
};

class FreeParking {
    std::vector<Player*> players; // Players who have landed on the free parking space
    int jackpot; // The amount of money accumulated in the free parking jackpot
};

class House {
    std::string name; // Name of the house
    int cost; // Cost to build the house
    Player* owner; // Owner of the house
    int rent; // Rent to be paid by players who land on a property with this house
};

class Hotel {
    std::string name; // Name of the hotel
    int cost; // Cost to build the hotel
    Player* owner; // Owner of the hotel
    int rent; // Rent to be paid by players who land on a property with this hotel
};

#endif