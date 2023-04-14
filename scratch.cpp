#include<bits/stdc++.h>
using namespace std;
int i=0;
class Car{
    public:
        string make="";
        string model="";
        int year;
        int x=0;
        int y=0;            //setting initial coordinates and speeds to zero
        int z=0;
        int speed_x=0;
        int speed_y=0;
        int speed_z=0;
        
        
        Car(){          //this is a constructor which sets the corresponding values given by user
            cout<<"This is the "<<i+1<<"th car\n";
            cout<<"Enter the make of the car (e.g., Hyundai, Maruti, BMW) : ";
            cin>>make;
            cout<<"Enter the model of the car (e.g., Alto, Creta, City) : ";
            cin>>model;
            cout<<"Enter the year the car was made : ";
            cin>>year;
            cout<<"Enter the x,y,z coordinates (separated by spaces): ";
            cin>>x>>y>>z;
            cout<<"Enter the x,y,z componants of speed (separated by spaces): ";
            cin>>speed_x>>speed_y>>speed_z;
            i++;
        }
        
        
        int menu(){     //menu which will perform different functions based on user's choice
            cout<<"         Select a choice for the 1st car\n";
            cout<<"1. Print the data\n";
            cout<<"2. Accelerate\n";
            cout<<"3. Decelerate\n";
            cout<<"4. Move\n";
            cout<<"5. Check if the car has collided with 2nd car\n";
            cout<<"6. Check the time of collision with 2nd car\n";
            cout<<"7. Exit\n";
            int choice;
            cin>>choice;
            switch(choice){
                case 1:
                    printCurrentData();
                    return 1;
                case 2:
                    int ax,ay,az;
                    cout<<"Enter increments in speeds(x,y,z, separated by spaces) : ";
                    cin>>ax>>ay>>az;
                    accelerate(ax,ay,az);
                    return 1;
                case 3:
                    int dx,dy,dz;
                    cout<<"Enter decrements in speeds(x,y,z, separated by spaces) : ";
                    cin>>dx>>dy>>dz;
                    decelerate(dx,dy,dz);
                    return 1;
                case 4:
                    move();
                    return 1;
                case 5:
                    return 5;
                case 6:
                    return 6;
                case 7:
                    cout<<"Bye :)";
                    return 7;
            }
        }
        
        
        void printCurrentData(){        //method to print current data for a car    
            cout<<"Model : "<<model<<endl;
            cout<<"Make : "<<make<<endl;
            cout<<"Year the car was made : "<<year<<endl;
            printf("Coordinates : (%d,%d,%d)\n",x,y,z);
            printf("Speeds(x,y,z) : (%d,%d,%d)\n",speed_x,speed_y,speed_z);
        }
        
        
        void accelerate(int inc_x,int inc_y,int inc_z){ //method to accelerate a car   
            this->speed_x+=inc_x;       //using this-> to increment the speed of that particular car
            this->speed_y+=inc_y;
            this->speed_z+=inc_z;
            cout<<"\n           Successfully accelerated\n";
        }
        
        
        void decelerate(int dec_x,int dec_y,int dec_z){     //method to decelerate a car
            this->speed_x-=dec_x;
            this->speed_y-=dec_y;
            this->speed_z-=dec_z;
            cout<<"\n           Successfully decelerated\n";
        }
        
        
        void move(){        //method to move a car for 1 second
            x+=speed_x;
            y+=speed_y;
            z+=speed_z;
            cout<<"     Successfully moved\n";
        }
        
        
        void detectCollision(Car c){        //method to detect if the two cars have collided
            if(c.x==x&&c.y==y&&c.z==z){
                cout<<"         The two cars have collided :(\n";
                return;
            }
            else{
                cout<<"         The two cars have not yet collided :)\n";
                return;
            }
        }
        
        
        void timeToCollision(Car c){        /*method to detect if the two cars may collide in the future,
                                            which prints the time till collision if the two cars will collide*/
            int rx=c.x-x;
            int ry=c.y-y;
            int rz=c.z-z;
            if(rx==0&&ry==0&&rz==0){    //if relative distance is already zero then the cars will collide
                cout<<"     The two cars have already collided :(\n";
                return;
            }
            int vx=c.speed_x-speed_x;
            int vy=c.speed_y-speed_y;
            int vz=c.speed_z-speed_z;
            if(vx==0&&vy==0&&vz==0){    //if relative velocity is zero given relative distance !=0 then cars wont collide
                cout<<"     The two cars will not collide at current positions and speeds:)\n";
                return;
            }
            int dot=rx*vx+ry*vy+rz*vz;
            int mag_r=rx*rx+ry*ry+rz*rz;
            int mag_v=vx*vx+vy*vy+vz*vz;
            if(dot==-sqrt(mag_r*mag_v)){  //checking if angle between relative distance and relative velociy is pi
                cout<<"     The two cars will collide at current positions and speeds :(\n";
                cout<<"     The time of collision is : "<<sqrt((float)(mag_r)/(float)mag_v)<<" seconds\n";
                 cout<<"     The distance of collision from the second car is : "<<mag_v*sqrt((float)(mag_r)/(float)mag_v)<<" units\n";
                //the above line prints the distance of collision from the second car
                return;

            }
            else{
                cout<<"     The cars will not collide at current positions and speeds :)";
                return;
            }
       }
};
int main(){
    Car c1,c2;
    int q=0;
    while(1){
        cout<<"\n";
        int t=c1.menu();
        switch(t){
            case 5:
                c1.detectCollision(c2);
                break;
            case 6:
                c1.timeToCollision(c2);
                break;
            case 7:         //exiting the loop if the user does not want to proceed further
                q=1;
                break;
        }
        if(q==1) break;
    }
    return 0;
}