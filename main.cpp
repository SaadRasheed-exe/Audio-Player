#include "InCarAudioPlayer.h"
#include <thread>
#include <conio.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

const int numOfMedias = 100;
bool leaving = false;

Song *songList;
int songCount;

StorageMedia* arr[numOfMedias];

InCarAudioPlayer obj("Beats", "TK-045");

StorageMedia* mediaMenu()
{
    while (true)
    {
        system("cls");
        cout << "Select a storage media:-" << endl;
        int count = 0;
        for (size_t i = 0; i < numOfMedias; i++)
        {
            if (arr[i])
            {
                cout << ++count << ". " << arr[i]->getName() << " - " << arr[i]->getNoOfSongs() << " songs stored." << endl;
            }
        }
        cout << "Choose the storage media: ";
        int choice = 0;
        cin >> choice;
        int count2 = 0;
        for (size_t i = 0; i < numOfMedias; i++)
        {
            if (arr[i])
            {
                ++count2;
                if (count2 == choice)
                {
                    return arr[i];
                }
            }
        }
    }
}

void currState()
{
    std::cout << "Audio Player: " << obj.getModel() << " by " << obj.getManufacturer() << std::endl;
    if (obj.getPower())
    {
        if (obj.getMounted())
        {
            if (obj.getCurrSong().getFileName() == "NULL")
            {
                std::cout << "Playlist ended." << std::endl;
            }
            else
            {
                std::cout << "Current Song: " << obj.getCurrSong().getTitle() << std::endl;
            }
        }
        else
        {
            std::cout << "No storage media mounted." << std::endl;
        }
    }
    else
    {
        std::cout << "Powered off." << std::endl;
    }
}

int mainMenu()
{
    int choice = 0, count = 0;
    currState();
    if (obj.getPower())
    {
        std::cout << ++count << ". Power off." << std::endl;
        if (obj.getMounted())
        {
            std::cout << ++count << ". Unmount " << obj.getMounted()->getName() << '.' << std::endl;
        }
        else
        {
            std::cout << ++count << ". Mount a storage media." << std::endl;
        }
    }
    else
    {
        std::cout << ++count << ". Power on." << std::endl;
    }
    std::cout << ++count << ". Exit." << std::endl;

    std::cout << "Enter an option: ";
    std::cin >> choice;
    if (choice == count)
    {
        return 10;
    }
    return choice;
}

void init()
{
    arr[0] = new CD();
    arr[1] = new CD(3, "WAV", "Verbatim CD-R");
    arr[2] = new USB();
    arr[3] = new USB(32, "Toshiba USB");

    for (int i = 4; i < numOfMedias; i++)
    {
        arr[i] = NULL;
    }

    songCount = 0;

    DIR* dr;
    struct dirent* en;
    dr = opendir(".");
    if (dr)
    {
        while ((en = readdir(dr)) != NULL)
        {
            if (check(en->d_name))
            {
                songCount++;
            }
        }
        closedir(dr);
    }

    songList = new Song[songCount];

    dr = opendir(".");
    if (dr)
    {
        int i = 0;
        while ((en = readdir(dr)) != NULL)
        {
            if (check(en->d_name))
            {
                songList[i] = Song(en->d_name);
                i++;
            }
        }
        closedir(dr);
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < songCount; j++)
        {
            if (arr[i]->addMusic(songList[rand() % songCount]) == "capacity")
            {
                break;
            }
        }
    }

    /*Song a("Hawayein - Arijit Singh.mp3");
    Song b("Kun Faya Kun - A.R. Rahman, Mohit Chauhan.mp3");
    Song c("Maroon 5 - Memories.mp3");
    Song d("Caslow-_-Exede-City-Lights.wav");
    Song e("Deep-Blue-William-Black-ft.-Monika-Santucci.wav");
    Song f("Khamoshiyan-Arijit-Singh.wav");
    Song g("The-Chainsmokers-_-Coldplay-Something-Just-Like-This.wav");

    arr[0]->addMusic(a);
    arr[0]->addMusic(b);
    arr[0]->addMusic(c);

    arr[1]->addMusic(f);
    arr[1]->addMusic(g);
    arr[1]->addMusic(d);

    arr[2]->addMusic(f);
    arr[2]->addMusic(b);
    arr[2]->addMusic(a);

    arr[3]->addMusic(c);
    arr[3]->addMusic(g);
    arr[3]->addMusic(e);
    arr[3]->addMusic(d);*/
    
}


void bgmusic()
{
    while (obj.getPower() && obj.getMounted() && obj.getCurrSong().getFileName() != "NULL")
    {
        while (BASS_ChannelIsActive(obj.getCurrSong().getChannel()) && obj.getPower())
        {
            Sleep(1000);
        }
        std::thread worker(refresh);
        obj.playNext();
        worker.join();
    }
}

int main()
{
    if (!BASS_Init(-1, 44100, 0, 0, 0)) return 0;

    init();

    bool exit = false;

    while (!exit)
    {
        system("cls");
        switch (mainMenu())
        {
        case 1:
            obj.powerToggle();
            if (obj.getPower())
            {
                std::thread worker(bgmusic);
                worker.detach();
            }
            break;
        case 2:
            if (obj.getMounted())
            {
                obj.unmount();
            }
            else
            {
                obj.mount(mediaMenu());
                if (obj.getPower())
                {
                    std::thread worker(bgmusic);
                    worker.detach();
                }
            }
            break;
        case 10:
            exit = true;
            leaving = true;
            break;
        default:
            break;
        }
    }
}