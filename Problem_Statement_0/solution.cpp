#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

int main(){
    int no_of_ships;
    cout<<"How many ships are to be processed?"<<endl;
    cin>>no_of_ships;
    int runner=1;
    while (runner <= no_of_ships){
    
        std::vector<int> container_no;
        cout<<"Enter the maximum storage capacity of port: ";
        int c;
        cin>>c;
        cout<<"Enter the number of containers: ";
        int N;
        cin>>N;
        std::vector<int> weight;
        int a;
        for (int i = 0; i<N; i++){
            cout<<"Enter the weight on container "<<i+1<<" : ";
            cin>>a;
            container_no.push_back(i+1);
            weight.push_back(a);
        }
        cout<<"Got it! The data you need is:\n";

        int total_shipment_weight = 0;
        for(int i=0; i<weight.size();i++){
            total_shipment_weight = total_shipment_weight + weight[i];
        }

        double avg_cont_weight = total_shipment_weight/N;

        // Finding MAX
        int max = weight[0];
        for (int i=0; i<weight.size();i++){
            if (weight[i]>max){
                max = weight[i];
            }}
        

        // Finding MIN
        int min = weight[0];
        for (int i=0; i<weight.size();i++){
            if (weight[i]<min){
                min = weight[i];
            }
        }

        cout<<"The total shipment weight is: "<<total_shipment_weight<<endl;
        cout<<"The average container weight is: "<<avg_cont_weight<<endl;
        cout<<"The Heaviest container has the weight: "<<max<<endl;
        cout<<"The Lightest container has the weight: "<<min<<endl;
        (total_shipment_weight > 200) ? cout<<"The classification is heavy\n":cout<<"The classification is light";
        cout<<"The port capacity is: "<<c<<endl;
        cout<<"The status is: ";
        (total_shipment_weight>c) ? cout<<"Shipment exceeds port capacity" : cout<<"Shipment can be unloaded";

        // Level 2

        // sorting weight:

        std::vector<int> fakeweight = weight;

        cout<<endl<<endl<<"The weights of the ships arranged in an order are: "<<endl;
        int temp;
        for(int i=0; i<fakeweight.size()-1;i++){
            for (int j=0; j<fakeweight.size()-i-1;j++){
                if (fakeweight[j]>fakeweight[j+1])
                {
                    temp=fakeweight[j];
                    fakeweight[j]=fakeweight[j+1];
                    fakeweight[j+1]=temp;

                    temp=container_no[j];
                    container_no[j]=container_no[j+1];
                    container_no[j+1]=temp;
                }
                
            }
        }

        for(int i=0; i<fakeweight.size();i++){
            cout<<i+1<<" : "<<fakeweight[i]<<"kg belonging to container number "<<container_no[i]<<endl;
        }

        // Bar chart using *
        cout<<endl<<endl;
        cout<<"For analysis of given data using Bar chart"<<endl;
        for(int i=0; i<weight.size();i++){
            cout<<"Container no. "<<container_no[i]<<" : ";
            for (int j = 0; j<fakeweight[i];j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        runner++;
        return 0;            
        }

        

        

    }
