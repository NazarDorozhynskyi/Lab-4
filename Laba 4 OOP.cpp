
#include <iostream>
using namespace std;

class Advertisement {
private:
    string adv_name;
    string customer;

public:
    Advertisement() {
        cout << "Викликаємо базовий  конструктор без параметрів..." << endl;
        adv_name = "DEFAULT_NAME";
        customer = "DEFAULT_CUSTOMER";
    }

    Advertisement(const string& adv_name, const string& customer) :
            adv_name(adv_name), customer(customer) {
        cout << "Викликаємо базовий  конструктор з параметрами..." << endl;
    }

    Advertisement(const Advertisement& adv) {
        cout << "Викликаємо базовий  конструктор копіювання..." << endl;
        adv_name = adv.adv_name;
        customer = adv.customer;
    }

    ~Advertisement() {
        cout << "Викликаємо базовий  деструктор..." << endl;
    }

    string GetName() const {
        return adv_name;
    }
    string GetCustomer() const {
        return customer;
    }

    void SetName(string name) {
        adv_name = name;
    }

    void SetCustomer(string cust) {
        customer = cust;
    }

    void GetFullInfo() const {
        cout << "\nAdvertisement name: " << GetName() <<
                "\nCustomer:" << GetCustomer() << "\n\n";
    }
};

class AdvertisementTV : public Advertisement {
private:
    string TVchannel_name;
    double duration_of_1_video;
    double number_of_showings_per_week;
    double cost_show_1_minute;

public:
    AdvertisementTV() {
        cout << "Викликаємо похідний конструктор без параметрів..." << endl;
        TVchannel_name = "DEFAULT_TV_CHANNEL_NAME";
        duration_of_1_video = 1;
        number_of_showings_per_week = 1;
        cost_show_1_minute = 1;
    }

    AdvertisementTV(const string& adv_name, const string& customer,
                    const string& TVchannel_name,
                    const double& duration_of_1_video,
                    const double& number_of_showings_per_week,
                    const double& cost_show_1_minute) :
            Advertisement(adv_name, customer),
            TVchannel_name(TVchannel_name),
            duration_of_1_video(duration_of_1_video),
            number_of_showings_per_week(number_of_showings_per_week),
            cost_show_1_minute(cost_show_1_minute) {
        cout << "Викликаємо похідний конструктор з параметрами..." << endl;
    }

    ~AdvertisementTV() {
        cout << "Викликаємо похідний деструктор..." << endl;
    }

    string GetTVchannel_name() const {
        return TVchannel_name;
    }

    double GetDuration_of_1_video() const {
        return duration_of_1_video;
    }

    double GetNumber_of_showings_per_week() const {
        return number_of_showings_per_week;
    }

    double GetCost_show_1_minute() const {
        return cost_show_1_minute;
    }

    void SetTVchannel_name(string TVchannel) {
        TVchannel_name = TVchannel;
    }

    void SetDuration_of_1_video(double duration) {
        duration_of_1_video = duration;
    }

    void SetNumber_of_showings_per_week(double showings_week) {
        number_of_showings_per_week = showings_week;
    }

    void SetCost_show_1_minute(double show_1_minute) {
        cost_show_1_minute = show_1_minute;
    }

    double TotalCostOfOrders() const {
        return number_of_showings_per_week * duration_of_1_video * cost_show_1_minute;
    }

    void GetFullInfoTV() const {
        cout << "\nTV Channel name: " << GetTVchannel_name() <<
                "\nDuration of 1 video: " << GetDuration_of_1_video() <<
                "\nNumber of showings per week: " << GetNumber_of_showings_per_week() <<
                "\nCost show 1 minute: " << GetCost_show_1_minute() << "\n\n";
    }
};

bool operator > (const AdvertisementTV& adv1, const AdvertisementTV& adv2) {
    return adv1.TotalCostOfOrders() > adv2.TotalCostOfOrders();
}

bool operator < (const AdvertisementTV& adv1, const AdvertisementTV& adv2) {
    return adv1.TotalCostOfOrders() < adv2.TotalCostOfOrders();
}

int main() {
    system("chcp 1251");

AdvertisementTV adv1("NESTLE", "AMAZON", "NATIONAL GEOGRAPHIC", 15.1, 32, 4.2);
    AdvertisementTV adv2("COCA-COLA", "TESLA", "FIRST CHANNEL", 22.7, 56, 15.6);
    AdvertisementTV adv3("PEPSI", "SPACEX", "DISCOVERY", 31.5, 7, 16.3);

    AdvertisementTV *arrAdv[] = {&adv1, &adv2, &adv3};
    AdvertisementTV *arrAdvTemp;

    int k1, k2, kst, i;
    double sum;
    kst = sizeof(arrAdv)/sizeof(*arrAdv);

    cout << "\n\t\t****************\n\t\t*Insertion Sort*\n\t\t****************\n\n";
    for (k1 = 1; k1 < kst; k1++) {
        arrAdvTemp = *(arrAdv+k1);
        k2 = k1-1;
        while (k2 >= 0 and (*arrAdvTemp > *arrAdv[k2])) {
            (arrAdv[k2+1]) = arrAdv[k2];
            k2--;
        }
        arrAdv[k2+1] = arrAdvTemp;
    }

    for (i = 0; i < kst; i++) {
        cout << "Cost of " << i+1 << " Advertisement TV order: " << arrAdv[i] -> TotalCostOfOrders() << " \n";
        sum += arrAdv[i] -> TotalCostOfOrders();
        arrAdv[i] -> GetFullInfoTV();
    }
    cout << "\t Total sum of all orders: " << sum << "\n\n";

    return 0;
}
