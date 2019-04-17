#include <iostream>
#include <vector>

#include "pokemon.h"


std::vector<Pokemon> initializePokemons()
{
    std::vector<Pokemon> pokemons;

    pokemons.push_back(Pokemon("Balbasaur", "leaf", "water"));
    pokemons.push_back(Pokemon("Pikatchu", "electric", "water"));
    pokemons.push_back(Pokemon("Charizard", "fire", "leaf"));
    pokemons.push_back(Pokemon("Balbasaur", "water", "fire"));
    pokemons.push_back(Pokemon("Kingler", "water", "fire"));

    return pokemons;
}

int main(int argc, char *args[])
{
    std::vector<Pokemon> pokemonOfAsh = initializePokemons();

    // Every pokemon has a name and a type.
    // Certain types are effective against others, e.g. water is effective against fire.

    // Ash has a few pokemon.
    // A wild pokemon appeared!

    Pokemon wildPokemon("Oddish", "leaf", "water");

    std::vector<std::string> chosenPokemon;
    for (unsigned int i = 0; i < pokemonOfAsh.size(); i++) {
        if (pokemonOfAsh.at(i).isEffectiveAgainst(wildPokemon)) {
            chosenPokemon.push_back(pokemonOfAsh.at(i)._name);
        }
    }

    // Which pokemon should Ash use?
    for (unsigned int i = 0; i < chosenPokemon.size(); i++) {
        std::cout << "I choose You, " << chosenPokemon[i] << std::endl;
    }

    return 0;
}