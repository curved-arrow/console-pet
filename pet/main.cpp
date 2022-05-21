#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
	private:
		string name;
	
	public:
		
		User(string name) {
			this->name = name;
		}
		
		vector<string> task_list;
		
		void set_name(string name) {
			this->name = name;
		}
		
		void set_task_list_item(string item) {
			task_list.push_back(item);
		}
		
		void remove_task_list_item(signed int pop_index) {
			task_list.erase(task_list.begin() + pop_index);
		}
		
		void get_task_list() {
			for(int i = 0; i < task_list.size(); i++) {
				cout << i << + " "<< task_list.at(i) << endl;
			}
		}
};

class Pet {
	private:
		string name;
		signed int age;
		signed int gender; // 0 = female, 1 = male, anything else is "other"
		signed int race;
		signed int time;
		signed int date;
		string day;
	
	public:
		string age_directory;
		string gender_directory;
		string race_directory;
		string image;

		Pet(string name, signed int age, signed int gender, signed int race) {
			this->name = name;
			this->age = age;
			this->gender = gender;
			
			
			if(race == 0) {
				race_directory = "human";
			} else if(race == 1) {
				race_directory = "animal";
			} else {
				race_directory = "monster";
			}
			
			if(age < 18 && age >= 13) {
				age_directory = "teen";
			} else if(age < 10) {
				age_directory = "child";
			} else if(age >= 18) {
				age_directory = "adult";
			} else {
				age_directory = "generic";
			}
			
			if(gender == 0) {
				gender_directory = "female";
			} else if(gender == 1) {
				gender_directory = "male";
			} else {
				gender_directory = "other";
			}
			
			this->image = race_directory + age_directory + gender_directory;
		}
		
		vector<string> greetings = {"Welcome!", "Nice to see you again!", "I'm glad to see you!", "Let's get started!"};
		signed int greeting_counter = greetings.size()-1;
		
		vector<string> attentions = {"Hey, listen! Give me pets!", "Ring ring, do you hear that? Time for pets!", "Pet me I'm dying!", "Kept you waiting huh? Pet me!", "Pet me"};
		signed int attentions_counter = attentions.size();
		
		int default_timer; // timer for 25 minutes
		signed int interaction_timer; // countdown from last interaction
		
		void set_time(int time) {
			this->time = time;
		}
		
		void set_date(int date) {
			this->date = date;
		}
		
		void set_day(string day) {
			this->day = day;
		}
		
		void get_time() {
			cout << this->time << endl;
		}
		
		void get_date() {
			cout << this->date << endl;
		}
		
		void get_day() {
			cout << this->day << endl;
		}		
		
		void give_pets() {
			interaction_timer = default_timer;
			cout << "Thank you for petting me, I love you" << endl;
		}
		
		void give_food() {
			interaction_timer = default_timer;
			cout << "Thank you for feeding me, I love you" << endl;
		}
		
		void give_exercise() {
			interaction_timer = default_timer;
			cout << "Thank you for helping me stay fit, I love you" << endl;
		}
		
		void display_greeting() {
			
			cout << greetings.at(greeting_counter) << endl;
			greeting_counter--;
			
			if(greeting_counter < 0) {
				
				greeting_counter = greetings.size();
			}
		}
		
		void display_attention() {
			
			cout << attentions.at(attentions_counter) << endl;
			attentions_counter--;
			
			if(attentions_counter < 0) {
				
				attentions_counter = attentions.size();
			}
		}
		
		void set_name(string name) {
			this->name = name;
		}
		
		void set_age(int age) {
			this->age = age;
		}
		
		void set_gender(int gender) {
			this->gender = gender;
		}
		
		void get_gender() {
			int temp_gender = this->gender;
			if(temp_gender == 0) {
				cout << "Female" << endl;
			} else if(temp_gender == 1){
				cout << "Male" << endl;
			} else {
				cout << "I'm not Male or Female!" << endl;
			}
		}

		void get_name() {
			cout << this->name << endl;
		}
		
		void get_age() {
			cout << this->age << endl;
		}
		
		void set_race(int race) {
			this->race = race;
		}
		
		void get_race() {
			cout << this->race << endl;
		}
		
		void get_image() {
			cout << this->image << endl;
		}
};

int main() {
signed int initial;
signed int keep_on;
signed int pet_menu;
User USER("default");
Pet PET("default", 0, 0, 0);

signed int zero_choice;
signed int first_choice, second_choice, third_choice, fourth_choice, fifth_choice, pet_age, pet_gender, pet_race;
string user_name, pet_name;
	
do {
	
	do {
		
		signed int zero_choice_temp;
		cout << "Hello there and welcome to your Virtual Pet Experience!" << endl;
		cout << "What is your name?" << endl;
		user_name = "debug user";
	//	cin >> user_name;
		
		cout << "Are you happy with your name? (0 = yes, 1 = no)" << endl;
		cin >> zero_choice_temp;
		
		zero_choice = zero_choice_temp;
		
		} while (zero_choice == 1);

	do {
		
		do {
			cout << "What do you want your pet's name to be?" << endl;
			pet_name = "Debug name";
//			cin >> pet_name;
			
//			cout << "That's an excellent choice are you happy with it? (0 for yes)" << endl;
//			cin >> first_choice;
			first_choice = 0;
			
		} while (first_choice != 0);
		
		do {
			cout << "How old is your pet?" << endl;
			pet_age = 18;
//			cin >> pet_age;
			
//			cout << "That's an excellent choice are you happy with it? (0 for yes)" << endl;
//			cin >> second_choice;
			second_choice = 0;
				
		} while (second_choice != 0);
		
		do {
			cout << "What gender is your pet (Currently pets are human)?" << endl;
			pet_gender = 0;
//			cin >> pet_gender;
			
//			cout << "That's an excellent choice are you happy with it? (0 for yes)" << endl;
//			cin >> third_choice;
			third_choice = 0;
				
		} while (third_choice != 0);
		
		do {
			cout << "What race is your pet (0 for human, 1 for random animals, or any other number for random monsters)?" << endl;
			pet_race = 0;
//			cin >> pet_race;
			
//			cout << "That's an excellent choice are you happy with it? (0 for yes, 1 for no)" << endl;
//			cin >> fourth_choice;
			fourth_choice = 0;
				
		} while (fourth_choice != 0);
		
//		cout << "Are you happy with your selection (0 for yes, 1 for no)?" << endl;
//		cin >> fifth_choice;

	} while (fifth_choice != 0);
	
	cout << "We will now meet your new pet!" << endl;
	
	PET.set_name(pet_name);
	PET.set_age(pet_age);
	PET.set_gender(pet_gender);
	PET.set_race(pet_race);
	
	PET.display_greeting();
	PET.get_image();

	initial = 0;
	} while (initial != 0);
	
	keep_on = 1;
	
	do {
		// display pet
		// countdown time every 25 minutes
		
		signed int pet_menu_choice;
		
		signed int pet_setters_menu;
		signed int setters_choice;
		string pet_new_name;
		int pet_new_age;
		int pet_new_gender;
		int pet_new_race;
		
		
		signed int pet_interaction_menu;
		signed int interaction_choice;
		
		signed int task_list_setters_menu;
		signed int task_list_choice;
		string add_item;
		
		signed int task_list_getters_menu;
		signed int task_list_getters_choice;
		
		signed int task_list_removal_menu;
		signed int remove_item;
		
		cout << "Access the pet menu? (0 = turn off (will not save), 1 = interaction menu, 2 = settings menu, 3 = create your task list, 4 = view your task list, )" << endl;
		cin >> pet_menu_choice;
		
		switch(pet_menu_choice) {
			case 1:
				while (pet_interaction_menu != 0) {
				
				cout << "How do you want to interact with your pet? (0 = no interaction, 1 = feed, 2 = exercise, 3 = pet me)" << endl;
				cin >> interaction_choice;
				
				switch(interaction_choice) {
					case 1:
						PET.give_food();
						break;
					case 2:
						PET.give_exercise();
						break;
					case 3:
						PET.give_pets();
						break;
					default:
						pet_interaction_menu = 0;
						break;
					}
				}
				break;
		
			case 2:					
				pet_setters_menu = 1;
				while (pet_setters_menu != 0) {
					cout << "Warning, changing these settings will change the image of your pet." << endl;
					cout << "What do you want to change? 0 = nothing, 1 = name, 2 = age, 3 = gender, 4 = race" << endl;
					cin >> setters_choice;
	
					switch(setters_choice) {
					
						case 1:
							cout << "Type your pet's new name: " << endl;
							cin >> pet_new_name;
							PET.set_name(pet_new_name);
							PET.get_name();
							break;
						case 2:
							cout << "Type your pet's new age: " << endl;
							cin >> pet_new_age;
							PET.set_age(pet_new_age);
							PET.get_age();
							break;
						case 3:
							cout << "Type your pet's new gender: " << endl;
							cin >> pet_new_gender;
							PET.set_age(pet_new_gender);
							PET.get_gender();
							break;
						case 4:
							cout << "Type your pet's new race: " << endl;
							cin >> pet_new_race;
							PET.set_race(pet_new_race);
							PET.get_race();
							break;
						default:
							pet_setters_menu = 0;
							break;
					}
				} break;
			
			case 3:
				task_list_setters_menu = 1;
				while (task_list_setters_menu != 0) {
					cout <<  "Do you want to add an item to your task list? 0 = no, 1 = yes" << endl;
					cin >> task_list_choice;
					
					switch(task_list_choice) {
						case 1:
							cout << "What do you want to add?" << endl;
							cin >> add_item;
							
							USER.set_task_list_item(add_item);
							cout << "Task list updated.";
							break;
						default:
							task_list_setters_menu = 0;
							break;
						}
					} break;
				
			case 4:
				task_list_removal_menu = 1;
				USER.get_task_list();

				while (task_list_removal_menu == 1) {
					cout << "Type the index of the item you wish to remove." << endl;
					cout << "If nothing is displayed, you currently don't have anything to do! (1000 to cancel)" << endl;
					cin >> remove_item;
					
					if (remove_item != 1000) {
						USER.remove_task_list_item(remove_item);
					}
					break;
		} break;
			
			default:
				pet_menu_choice = 0;
				break;
		}
		
		cout << "0 to close the app (will not save), 1 to stay" << endl;
		cin >> keep_on;
		
		
		} while (keep_on != 0);
	return 0;
}