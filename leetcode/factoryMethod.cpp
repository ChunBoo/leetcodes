#include<iostream>
using namespace std;

class IInterviewer
{
    public:
    virtual void askQuestions()=0;
};

class Developer:public IInterviewer
{
    public:
    void askQuestions() override{
        cout<<"Asking about design patterns!"<<endl;
    }
};

class CommunityExecutive:public IInterviewer
{
    public:
        void askQuestions() override{
            cout<<"Asking about community building!"<<endl;
        }
};

class HiringManager
{
    public:
    void takeInterview(){
        IInterviewer* interviewer=this->makeInterviewer();
        interviewer->askQuestions();
    }
    protected:
    virtual IInterviewer* makeInterviewer()=0;
};

template <typename Interviewer>
class OtherManager:public HiringManager{
    protected:
    IInterviewer* makeInterviewer() override{
        return new Interviewer();
    }
};

int main()
{
    HiringManager* devManager= new OtherManager<Developer>();
    devManager->takeInterview();

    HiringManager* marketingManager=new OtherManager<CommunityExecutive>();
    marketingManager->takeInterview();

}