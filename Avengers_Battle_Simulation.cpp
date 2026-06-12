#include <bits/stdc++.h>
using namespace std;
class qns
{
private:
    int p, d, e, h;

public:
    int get_p() { return p; }
    int get_d() { return d; }
    int get_e() { return e; }
    int get_h() { return h; }
    qns(int p1, int d1, int e1, int h1)
    {
        p = p1;
        if (p > 5000)
        {
            p = 5000;
        }
        d = d1;
        e = e1;
        h = h1;
        if (h < 0)
        {
            h = 0;
        }
    }
    qns(const qns &suit)
    {
        p = suit.p;
        if (p > 5000)
        {
            p = 5000;
        }
        d = suit.d;
        if (d < 0)
        {
            d = 0;
        }
        e = suit.e;
        h = suit.h;
        if (h < 0)
        {
            h = 0;
        }
    }
    qns()
    {
        p = 1000;
        d = 500;
        e = 300;
        h = 0;
    }
    qns &operator+(qns &suit2)
    {
        // Formula: (P1, D1, E1,H1) + (P2, D2, E2,H2) = (P1 + E2, D1 + D2, E1 + P2,H1)
        p += (suit2.e);
        if (p > 5000)
        {
            p = 5000;
        }
        d += (suit2.d);
        e += (suit2.p);
        return *this;
    }
    qns &operator-(int x)
    {
        // Formula: (P, D, E, H) - X = (P, D - X, E + X, H + X)
        d -= x;
        e += x;
        h += x;
        return *this;
    }
    qns &operator*(int x)
    {
        // Formula: (P, D, E, H) * X = (P+(P * X)/100), D, E + 5X, H + X)
        p = (p + (p * x) / 100);
        if (p > 5000)
        {
            p = 5000;
        }
        e = e + 5 * x;
        h = h + x;
        return *this;
    }
    qns &operator/(int x)
    {
        // Formula: (P, D, E, H) / X = (P, D + X, E, H - X)
        d += x;
        h -= x;
        if (h < 0)
        {
            h = 0;
        }
        return *this;
    }

    void boostPower(int x) // boost by actor i.r *x
    {
        (*this) * (x);
    }
    void boostPower(qns suit2) // boost using another suit i.e +suit2
    {
        (*this) + suit2;
    }

    bool operator==(qns &suit2) // compare suits
    {
        return ((p == suit2.get_p()) && (d == suit2.get_d()));
    }
    bool operator<(qns &suit2) // compare suits
    {
        return (p + d < suit2.get_p() + suit2.get_d());
    }

    bool is_sd() // bool function to check is suit shut down
    {
        return h > 500;
    }
    bool is_destroyed() // bool function to check is suit destroyed
    {
        return d <= 0;
    }
};
class avenger
{
private:
    string name;
    qns suit;
    int attackstrength;

public:
    avenger(string name_par, qns &suit_par, int strength)
    {
        name = name_par;
        suit = suit_par;
        attackstrength = strength;
    }
    void attack(avenger &enenmy)
    {
        enenmy.suit - attackstrength;
    }
    void upgrade_suit(qns &suit2)
    {
        suit.boostPower(suit2);
    }
    void repair(int x) // cool down by factor x i.e /x
    {
        suit / x;
    }
    void print_status()
    {
        cout << name << " " << suit.get_p() << " " << suit.get_d() << " " << suit.get_e() << " " << suit.get_h() << endl;
    }
    friend class battle;
};
class battle
{
private:
    queue<qns> suits;
    vector<avenger> heroes;
    vector<avenger> enemies;
    vector<string> battleLog;
    unordered_map<string, int> hero_list;
    unordered_map<string, int> enemy_list;

public:
    void startBattle() // all battle simulation is done here
    {
        int k, n, m;
        cin >> k >> n >> m;
        for (int i = 0; i < k; i++) // input for suits
        {
            int p, d, e, h;
            cin >> p >> d >> e >> h;
            qns suit(p, d, e, h);
            suits.push(suit);
        }
        for (int i = 0; i < n; ++i) // input for n avengers
        {
            string name;
            cin >> name;
            int attackstrength;
            cin >> attackstrength;
            if (!suits.empty()) // check if is suit is available
            {
                avenger hero(name, suits.front(), attackstrength);
                suits.pop();
                heroes.push_back(hero);
                hero_list[name] = heroes.size() - 1; // index=size-1
            }
            else
            { // if suit is not available
                cout << name << " is out of fight" << endl;
            }
        }
        for (int i = 0; i < m; ++i) // input for m enemies
        {
            string name;
            cin >> name;
            int attackstrength;
            cin >> attackstrength;
            if (!suits.empty()) // check if is suit is available
            {
                avenger enemey(name, suits.front(), attackstrength);
                enemies.push_back(enemey);
                suits.pop();
                enemy_list[name] = enemies.size() - 1; // index=size-1
            }
            else
            { // if suit is not available
                cout << name << " is out of fight" << endl;
            }
        }
        string s;
        cin >> s;
        if (s == "BattleBegin")
        {
            while (1)
            {
                string cmd;
                cin >> cmd;
                if (cmd == "Attack")
                {
                    string hero, enemey;
                    cin >> hero >> enemey;
                    auto it_h_hl = hero_list.find(hero);
                    auto it_h_el = enemy_list.find(hero);
                    auto it_e_el = enemy_list.find(enemey);
                    auto it_e_hl = hero_list.find(enemey);

                    if (it_h_hl != hero_list.end() && it_e_el != enemy_list.end())
                    {
                        // avenger attacks enemy
                        if (!heroes[it_h_hl->second].suit.is_destroyed() && !heroes[it_h_hl->second].suit.is_sd())
                        {

                            // cout << "hero can attack" << endl;

                            if (!enemies[it_e_el->second].suit.is_destroyed())
                            {
                                // cout << "enemy can be attacked" << endl;

                                heroes[it_h_hl->second].attack(enemies[it_e_el->second]);
                                battleLog.push_back(hero + " attacks " + enemey);
                                if (enemies[it_e_el->second].suit.is_destroyed())
                                {
                                    battleLog.push_back(enemey + " suit destroyed");
                                }
                                else if (enemies[it_e_el->second].suit.is_sd())
                                {
                                    battleLog.push_back(enemey + " suit overheated");
                                }
                            }
                        }
                    }
                    else if (it_h_el != enemy_list.end() && it_e_hl != hero_list.end())
                    {
                        // enemy attacks avenegr
                        if (!enemies[it_h_el->second].suit.is_destroyed() && !enemies[it_h_el->second].suit.is_sd())
                        {
                            if (!heroes[it_e_hl->second].suit.is_destroyed())
                            {
                                enemies[it_h_el->second].attack(heroes[it_e_hl->second]);
                                battleLog.push_back(hero + " attacks " + enemey);
                                if (heroes[it_e_hl->second].suit.is_destroyed())
                                {
                                    battleLog.push_back(enemey + " suit destroyed");
                                }
                                else if (heroes[it_e_hl->second].suit.is_sd())
                                {
                                    battleLog.push_back(enemey + " suit overheated");
                                }
                            }
                        }
                    }
                    else if (it_h_hl != hero_list.end() && it_e_hl != hero_list.end())
                    {
                        // avenger attacks avenger
                        if (!heroes[it_h_hl->second].suit.is_destroyed() && !heroes[it_h_hl->second].suit.is_sd())
                        {
                            if (!heroes[it_e_hl->second].suit.is_destroyed())
                            {
                                heroes[it_h_hl->second].attack(heroes[it_e_hl->second]);
                                battleLog.push_back(hero + " attacks " + enemey);
                                if (heroes[it_e_hl->second].suit.is_destroyed())
                                {
                                    battleLog.push_back(enemey + " suit destroyed");
                                }
                                else if (heroes[it_e_hl->second].suit.is_sd())
                                {
                                    battleLog.push_back(enemey + " suit overheated");
                                }
                            }
                        }
                    }
                    else if (it_h_el != enemy_list.end() && it_e_el != enemy_list.end())
                    {
                        // enemy attacks enemy
                        if (!enemies[it_h_el->second].suit.is_destroyed() && !enemies[it_h_el->second].suit.is_sd())
                        {
                            if (!enemies[it_e_el->second].suit.is_destroyed())
                            {
                                enemies[it_h_el->second].attack(enemies[it_e_el->second]);
                                battleLog.push_back(hero + " attacks " + enemey);
                                if (enemies[it_e_el->second].suit.is_destroyed())
                                {
                                    battleLog.push_back(enemey + " suit destroyed");
                                }
                                else if (enemies[it_e_el->second].suit.is_sd())
                                {
                                    battleLog.push_back(enemey + " suit overheated");
                                }
                            }
                        }
                    }
                }
                else if (cmd == "Repair")
                {
                    string hero;
                    cin >> hero;
                    int x;
                    cin >> x;
                    auto it_h = hero_list.find(hero);
                    auto it_e = enemy_list.find(hero);
                    if (it_h != hero_list.end())
                    {
                        // avenger is getting repaired
                        heroes[it_h->second].repair(x);
                        battleLog.push_back(hero + " repaired");
                    }
                    else if (it_e != enemy_list.end())
                    {
                        // enemy is getting repaired
                        enemies[it_e->second].repair(x);
                        battleLog.push_back(hero + " repaired");
                    }
                }
                else if (cmd == "BoostPowerByFactor")
                {
                    string hero;
                    cin >> hero;
                    int y;
                    cin >> y;
                    auto it_h = hero_list.find(hero);
                    auto it_e = enemy_list.find(hero);
                    if (it_h != hero_list.end())
                    {
                        // avenger is boosting power
                        heroes[it_h->second].suit.boostPower(y);
                        battleLog.push_back(hero + " boosted");
                        if (heroes[it_h->second].suit.is_sd())
                        {
                            battleLog.push_back(hero + " suit overheated");
                        }
                    }
                    else if (it_e != enemy_list.end())
                    {
                        // enemy is boosting power
                        enemies[it_e->second].suit.boostPower(y);
                        battleLog.push_back(hero + " boosted");
                        if (enemies[it_e->second].suit.is_sd())
                        {
                            battleLog.push_back(hero + " suit overheated");
                        }
                    }
                }
                else if (cmd == "BoostPower")
                {
                    string hero;
                    cin >> hero;
                    int p, d, e, h;
                    cin >> p >> d >> e >> h;
                    qns suit2(p, d, e, h);
                    auto it_h = hero_list.find(hero);
                    auto it_e = enemy_list.find(hero);
                    if (it_h != hero_list.end())
                    {
                        // avenger is boosting power
                        heroes[it_h->second].suit + suit2;
                    }
                    else if (it_e != enemy_list.end())
                    {
                        // enemy is boosting power
                        enemies[it_e->second].suit + suit2;
                    }
                }
                else if (cmd == "AvengerStatus")
                {
                    string hero;
                    cin >> hero;
                    auto it_h = hero_list.find(hero);
                    auto it_e = enemy_list.find(hero);
                    if (it_h != hero_list.end())
                    {
                        // print avenger status
                        heroes[it_h->second].print_status();
                    }
                    else if (it_e != enemy_list.end())
                    {
                        // print enemy status
                        enemies[it_e->second].print_status();
                    }
                }
                else if (cmd == "Upgrade")
                {
                    string hero;
                    cin >> hero;
                    auto it_h = hero_list.find(hero);
                    auto it_e = enemy_list.find(hero);
                    if (it_h != hero_list.end())
                    {
                        if (!suits.empty())
                        {
                            // avenger is upgrading
                            qns suit2 = suits.front();
                            suits.pop();
                            heroes[it_h->second].upgrade_suit(suit2);
                            battleLog.push_back(hero + " upgraded");
                        }
                        else
                        {
                            battleLog.push_back(hero + " upgrade Fail");
                        }
                    }
                    else if (it_e != enemy_list.end())
                    {
                        if (!suits.empty())
                        {
                            // enemy is upgrading
                            qns suit2 = suits.front();
                            suits.pop();
                            enemies[it_e->second].upgrade_suit(suit2);
                            battleLog.push_back(hero + " upgraded");
                        }
                        else
                        {
                            battleLog.push_back(hero + " upgrade Fail");
                        }
                    }
                }
                else if (cmd == "PrintBattleLog")
                {
                    for (auto i = 0; i < battleLog.size(); ++i)
                    {
                        cout << battleLog[i] << endl;
                    }
                }
                else if (cmd == "BattleStatus")
                {
                    if (Result() == 1)
                    {
                        cout << "heroes are winning" << endl;
                    }
                    else if (Result() == -1)
                    {
                        cout << "enemies are winning" << endl;
                    }
                    else if (Result() == 0)
                    {
                        cout << "tie" << endl;
                    }
                }
                else if (cmd == "End")
                {
                    return;
                }
            }
        }
    }
    void printBattleLog()
    {
        for (int i = 0; i < battleLog.size(); i++)
        {
            cout << battleLog[i] << endl;
        }
    }
    int Result()
    {
        long long int hero_sum = 0, enemy_sum = 0;
        for (auto i = 0; i < heroes.size(); ++i)
        {
            if (!heroes[i].suit.is_destroyed()) // add only heroes that are not destroyed
            {
                hero_sum += (heroes[i].suit.get_p() + heroes[i].suit.get_d());
            }
        }
        for (auto i = 0; i < enemies.size(); ++i)
        {
            if (!enemies[i].suit.is_destroyed()) // add only enemies that are not destroyed
            {
                enemy_sum += (enemies[i].suit.get_p() + enemies[i].suit.get_d());
            }
        }
        if (hero_sum > enemy_sum)
        {
            return 1; // avenegers won
        }
        else if (hero_sum < enemy_sum)
        {
            return -1; // enemies won
        }
        else
        {
            return 0; // tie
        }
    }
};
int main()
{
    battle battle1;
    battle1.startBattle();
}
