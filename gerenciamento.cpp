#include "gerenciamento.h"

Gerenciador::Gerenciador()
{
    choice = 0;
    playing = true;
    activeCharacter = 0;
    fileName = "characters.txt";
}

Gerenciador::~Gerenciador()
{
}

// Functions
void Gerenciador::initGame()
{
    createNewCharacter();
}

void Gerenciador::mainMenu()
{
    cout << "ENTER to continue..."
         << "\n";
    cin.get();
    system("CLS");

    if (this->characters[activeCharacter].isAlive())
    {

        cout << "= MAIN MENU ="
             << "\n"
             << "\n";

        cout << "= Active character: " << this->characters[activeCharacter].getName() << " Nr: " << this->activeCharacter + 1 << "/" << this->characters.size() << " ="
             << "\n"
             << "\n";

        cout << "0: Quit"
             << "\n";
        cout << "1: Travel"
             << "\n";
        cout << "2: Character sheet"
             << "\n";
        cout << "3: Create new character"
             << "\n";
        cout << "4: Select character"
             << "\n";

        cout << "\n";

        cout << "\n"
             << "Choice: ";
        cin >> this->choice;

        while (cin.fail() || this->choice > 9)
        {
            cout << "Faulty input!"
                 << "\n";
            cin.clear();
            cin.ignore(100, '\n');

            cout << "\n"
                 << "Choice (0 - 8): ";
            cin >> this->choice;
        }

        cin.ignore(100, '\n');
        cout << "\n";

        switch (this->choice)
        {
        case 0: // QUIT
            playing = false;

            break;

        case 1: // TRAVEL
            travel();

            break;

        case 2: // CHAR SHEET
            this->characterMenu();
            break;

        case 3: // CREATE NEW CHAR
            createNewCharacter();
            break;

        case 4: // SELECT CHAR
            selectCharacter();
            break;

        default:
            break;
        }
    }
    else
    {
        playing = false;
    }
}

void Gerenciador::createNewCharacter()
{
    string name = "";
    cout << "Character name: ";
    getline(cin, name);

    for (size_t i = 0; i < this->characters.size(); i++)
    {
        while (name == this->characters[i].getName())
        {
            cout << "Error! Character already exists!"
                 << "\n";
            cout << "Character name: ";
            getline(cin, name);
        }
    }

    characters.push_back(Aventureiro());
    activeCharacter = characters.size() - 1;
    characters[activeCharacter].inicializar(name);
}
void Gerenciador::characterMenu()
{
    do
    {
        system("CLS");
        cout << menu_title("CHARACTER MENU");

        cout << menu_divider();

        characters[activeCharacter].getStats();

        cout << menu_divider();

        cout << "= MENU ="
             << "\n";
        cout << menu_item(0, "Back");
        cout << menu_item(1, "Print Inventory");
        cout << menu_item(2, "Equip Item");
        cout << menu_item(3, "Character Stats");
        cout << "\n";
        cout << "Choice: ";

        cin >> this->choice;

        while (cin.fail() || this->choice < 0 || this->choice > 3)
        {
            cout << "Faulty input!"
                 << "\n";
            cin.clear();
            cin.ignore(100, '\n');

            cout << "= MENU ="
                 << "\n";
            cout << "0: Back"
                 << "\n";
            cout << "1: Print Inventory"
                 << "\n";
            cout << "2: Equip Item"
                 << "\n";
            cout << "3: Character Stats"
                 << "\n";
            cout << "\n";
            cout << "Choice: ";
            cin >> this->choice;
        }

        cin.ignore(100, '\n');
        cout << "\n";

        switch (this->choice)
        {
        case 1:
            cout << this->characters[this->activeCharacter].getInv();

            break;

        case 2:
            cout << this->characters[this->activeCharacter].getInv();

            cout << "Item index: ";
            cin >> this->choice;

            while (cin.fail() || this->choice < 0 || this->choice >= this->characters[this->activeCharacter].getInventorySize())
            {
                cout << "Faulty input!"
                     << "\n";
                cin.clear();
                cin.ignore(100, '\n');

                cout << "Item index: ";
                cin >> this->choice;
            }

            cin.ignore(100, '\n');
            cout << "\n";

            this->characters[this->activeCharacter].equipItem(this->choice);

            break;
        case 3:
            cout << this->characters[this->activeCharacter].getStats();

            break;
        default:
            break;
        }

        if (this->choice > 0)
        {
            cout << "ENTER to continue..."
                 << "\n";
            cin.get();
        }

    } while (this->choice > 0);
}

void Gerenciador::selectCharacter()
{
    cout << "Select character: "
         << "\n\n";

    for (size_t i = 0; i < this->characters.size(); i++)
    {
        cout << "Index: " << i << " = " << this->characters[i].getName() << "\n";
    }

    cout << "\n";

    cout << "Choice: ";

    cin >> this->choice;

    while (cin.fail() || this->choice >= this->characters.size() || this->choice < 0)
    {
        cout << "Faulty input!"
             << "\n";
        cin.clear();
        cin.ignore(100, '\n');

        cout << "Select character: "
             << "\n";
        cin >> this->choice;
    }

    cin.ignore(100, '\n');
    cout << "\n";

    this->activeCharacter = this->choice;

    cout << this->characters[this->activeCharacter].getName() << " is SELECTED!"
         << "\n\n";
}

void Gerenciador::travel()
{
    this->characters[activeCharacter].travel();

    Combate ev;

    ev.generateEvent(this->characters[activeCharacter], this->enemies);
}

// MENU FUNCTIONS
const std::string Gerenciador::menu_title(const std::string title)
{
    std::stringstream ss;

    ss << "= " << title << " ="
       << "\n"
       << "\n";

    return ss.str();
}

const std::string Gerenciador::menu_divider(const unsigned amount, const char symbol)
{
    std::stringstream ss;

    ss << std::string(amount, symbol)
       << "\n"
       << "\n";

    return ss.str();
}

const std::string Gerenciador::menu_item(const unsigned index, const std::string text)
{
    std::stringstream ss;

    ss << "- "
       << "(" << index << ") " << text
       << "\n";

    return ss.str();
}