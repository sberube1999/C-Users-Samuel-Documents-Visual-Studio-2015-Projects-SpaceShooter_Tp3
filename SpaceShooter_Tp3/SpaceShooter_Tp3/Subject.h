#include "Observer.h"
//Temporaire, nous prenons un vecteur en attendant la structure de données
#include <vector>
using namespace std;

namespace spaceShooter
{
    class Subject
    {
    public:
        Subject();
        ~Subject();
        void Sub(Observer* subscriber);
        bool HasObservers() const;
    protected:
        vector<Observer*> observers;
    };
}