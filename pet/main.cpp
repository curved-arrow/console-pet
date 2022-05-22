#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
	private:
		string name; // here, we initialize a private variable that will only be accessible with getters and setters.
	
	public:
		
		// here is the class constructor
		User(string name) {
			this->name = name;
		}
		
		vector<string> task_list; // here we initialize a private vector (empty array of unknown size) where the user will add, display, or remove items
		
		// here is the setters for name
		void set_name(string name) {
			this->name = name;
		}
		
		// here is the getter for name
		void get_name() {
			cout << this->name << endl;
		}
		
		// here we allow the user to add an item to their to do list
		void set_task_list_item(string item) {
			task_list.push_back(item);
		}
		
		// here we allow the user to remove an item from their to do list
		void remove_task_list_item(signed int pop_index) {
			task_list.erase(task_list.begin() + pop_index);
		}
		
		// here we display the user's to do list
		void get_task_list() {
			for(int i = 0; i < task_list.size(); i++) {
				cout << i << + " "<< task_list.at(i) << endl;
			}
		}
};

class Pet {
	private:
		/* Initializes properties of the pet */
		string name; // name of the pet
		signed int age; // 3 categories: child, teen, adult
		signed int gender; // 0 = female, 1 = male, anything else is "other"
		signed int race; // 0 = human, 1 = animal (cat, dog), 2 = monster (cute monsters)
		signed int time; // variable that will store current time
		signed int date; // variable that will store current date
		string day; // variable that will store day name
	
	public:
		/* Initialize public variables using answers from the user's choices */
		string age_directory; // path of selected age group
		string gender_directory; // path of selected gender group
		string race_directory; // path of selected race group
		string image; // full path

		/* Constructor for Pet with Parameters */
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
		
		// Greetings vector stores all greeting
		vector<string> greetings = {"Welcome!", "Nice to see you again!", "I'm glad to see you!", "Let's get started!"};
		signed int greeting_counter = greetings.size()-1; // here store a counter to display a different greeting each time.
		
		// Attentions vector stores all attention
		vector<string> attentions = {"Hey, listen! Give me pets!", "Ring ring, do you hear that? Time for pets!", "Pet me I'm dying!", "Kept you waiting huh? Pet me!", "Pet me"};
		signed int attentions_counter = attentions.size(); // here store a counter to display a different attenntion message each time.
		
		int default_timer; // timer for 25 minutes to be used to display attention message, triggered if interaction_timer equals default_time
		signed int interaction_timer; // countdown from last interaction
		
		// this is used to set current time.
		void set_time(int time) {
			this->time = time;
		}
		
		// this is used to set current date.
		void set_date(int date) {
			this->date = date;
		}
		
		// this is used to set current day.
		void set_day(string day) {
			this->day = day;
		}
		
		// gets current time
		void get_time() {
			cout << this->time << endl;
		}
		
		// gets current date
		void get_date() {
			cout << this->date << endl;
		}
		
		// gets current day
		void get_day() {
			cout << this->day << endl;
		}		
		
		// when clicked, this is triggered to interact with the pet by petting it
		void give_pets() {
			interaction_timer = default_timer;
			cout << "Thank you for petting me, I love you" << endl;
		}
		
		// when clicked, this is triggered to interact with the pet by feeding it
		void give_food() {
			interaction_timer = default_timer;
			cout << "Thank you for feeding me, I love you" << endl;
		}
		
		// when clicked, this is triggered to interact with the pet by going for a walk with it
		// may be used to add a dungeon / side-scrolling feature (ala Chocobo World)
		void give_exercise() {
			interaction_timer = default_timer;
			cout << "Thank you for helping me stay fit, I love you" << endl;
		}
		
		// this function will display a greeting determined by the greeting counter, if greeting counter is less than 0 index, it will reset.
		void display_greeting() {
			
			cout << greetings.at(greeting_counter) << endl;
			greeting_counter--;
			
			if(greeting_counter < 0) {
				
				greeting_counter = greetings.size();
			}
		}
		
		// this function will display a attention message determined by the greeting counter, if attention counter is less than 0 index, it will reset.
		void display_attention() {
			
			cout << attentions.at(attentions_counter) << endl;
			attentions_counter--;
			
			if(attentions_counter < 0) {
				
				attentions_counter = attentions.size();
			}
		}
		
		// this is the setter for pet's name
		void set_name(string name) {
			this->name = name;
		}
		
		// this is the setter for pet's age
		void set_age(int age) {
			this->age = age;
		}
		
		// this is the setter for pet's gender
		void set_gender(int gender) {
			this->gender = gender;
		}
		
		// this is the setter for pet's race
		void set_race(int race) {
			this->race = race;
		}
		
		// this is the getter for pet's gender
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

		// this is the getter for pet's name
		void get_name() {
			cout << this->name << endl;
		}
		
		// this is the getter for pet's age
		void get_age() {
			cout << this->age << endl;
		}
		
		// this is the getter for pet's race
		void get_race() {
			cout << this->race << endl;
		}
		
		// this is the getter for pet's image path
		void get_image() {
			cout << this->image << endl;
		}
};

/* Here is the main class */
int main() {
	
	
	signed int initial; // here we initialize the do while trigger which tells us to do while the starting 
	signed int keep_on; // this trigger variable tells us to continue running the program until the user decides it's time to quit.
	signed int pet_menu; // this variable triggers nested do whiles that allow interaction with the pet, get/set pet properties, display/add/remove to do list.
	User USER("default"); // creates the user object. with "default" as the name.
	Pet PET("default", 0, 0, 0); // creates the pet object with default variables
	
	signed int zero_choice;
	signed int first_choice, second_choice, third_choice, fourth_choice, fifth_choice, pet_age, pet_gender, pet_race;
	string user_name, pet_name;
		
	
	do {
	/* Here is the initialize code block that is ran to create the user and pet with the user's choices. */
		do {
			// this code block we get the user's name
			signed int zero_choice_temp;
			cout << "Hello there and welcome to your Virtual Pet Experience!" << endl;
			cout << "What is your name?" << endl;
			cin >> user_name;
//			user_name = "debug user";
			
			cout << "Are you happy with your name? (0 = yes, 1 = no)" << endl;
			cin >> zero_choice_temp; // initializes this variable to escape or repeat this code block
			
			zero_choice = zero_choice_temp; // if the user is happy with their name, we are finished with this code block.
			
			} while (zero_choice == 1);
	
		do {
			
			do {
				// in this code block the user names the pet
				cout << "What do you want your pet's name to be?" << endl;
				cin >> pet_name;
//				pet_name = "Debug name"; // debug trigger
				
				cout << "That's an excellent choice are you happy with it? (0 for yes)" << endl;
				cin >> first_choice;
//				first_choice = 0; // debug trigger
				
			} while (first_choice == 1);
			
			do {
				// in this code block, the user choices the pet's age
				cout << "How old is your pet?" << endl;
				cin >> pet_age;
//				pet_age = 18; // debug trigger
				
				cout << "That's an excellent choice are you happy with it? (0 for yes)" << endl;
				cin >> second_choice;
//				second_choice = 0; // debug trigger
					
			} while (second_choice == 1);
			
			do {
				cout << "What gender is your pet (Currently pets are human)?" << endl;
				cin >> pet_gender;
//				pet_gender = 0; // debug trigger
				
				cout << "That's an excellent choice are you happy with it? (0 for yes)" << endl;
				cin >> third_choice;
//				third_choice = 0; // debug trigger
					
			} while (third_choice == 1);
			
			do {
				cout << "What race is your pet (0 for human, 1 for random animals, or any other number for random monsters)?" << endl;
				cin >> pet_race;
//				pet_race = 0; // debug variable
				
				cout << "That's an excellent choice are you happy with it? (0 for yes, 1 for no)" << endl;
				cin >> fourth_choice;
//				fourth_choice = 0; // debug trigger
					
			} while (fourth_choice == 1);
			
			cout << "Are you happy with your selection (0 for yes, 1 for no)?" << endl; // asks the user if they're happy with everything they chose.
			cin >> fifth_choice;
	
		} while (fifth_choice == 1);
		
		cout << "We will now meet your new pet!" << endl; // displayed once the user and pet have been created
		
		/* Here we use Pet Class setters and getters to set the properties to what the user chose */
		PET.set_name(pet_name);
		PET.set_age(pet_age);
		PET.set_gender(pet_gender);
		PET.set_race(pet_race);
		
		PET.display_greeting(); // display a greeting
		PET.get_image(); // display the image path (to be used to display on the screen
	
		initial = 0;
		} while (initial == 1);
		
		keep_on = 1; // here, we set the keep_on variable to run the keep the code running.
		
		do {
			/* To Do */
			// display pet with interaction buttons underneath
			// countdown time every 25 minutes
			
			signed int pet_menu_choice; // initialzies the do while trigger that allows user to interact with the program.
						
			signed int pet_interaction_menu; // initialzies the while trigger that allows user to interact with the pet.
			signed int interaction_choice; // initialzies the do while trigger that allows user to interact with the pet.
			
			signed int pet_setters_menu; // initialzies the do while trigger that allows user to change properties of the pet.
			signed int setters_choice; // this is a switch case that determines what pet properties the user will be changing.
			
			/* Here are the intialized variables that will be used in the setters_choice */
			string pet_new_name; // passed as an argument to the pet class set_name method.
			int pet_new_age; // passed as an argument to the pet class set_age method.
			int pet_new_gender; // passed as an argument to the pet class set_gender method.
			int pet_new_race; // passed as an argument to the pet class set_race method.
						
			signed int task_list_setters_menu; // initialzies the do while trigger that allows user to interact with their to do list.
			signed int task_list_choice; // this is a switch case that determines what pet properties the user will be doing with their to do list.
			string add_item; // passed as an argument to the user class set_task_list_item method
			
			signed int task_list_removal_menu; // initialzies the do while trigger that displays the user's to do list.
			signed int remove_item; // passed as an argument to the remove_task_list_item method from the user class.
			
			// displays the menu to the user
			cout << "Access the pet menu? (0 = turn off (will not save), 1 = interaction menu, 2 = settings menu, 3 = create your task list, 4 = view your task list, )" << endl;
			
			// using the displayed menu, the user will enter a corresponding choice.
			switch(pet_menu_choice) {
				case 1:
					while (pet_interaction_menu != 0) {
					
					// displays pet interaction menu.
					cout << "How do you want to interact with your pet? (0 = no interaction, 1 = feed, 2 = exercise, 3 = pet me)" << endl;
					cin >> interaction_choice; // this is used to determine the next course of action
					
					switch(interaction_choice) {
						case 1:
							PET.give_food(); // use's the pet class method
							break;
						case 2:
							PET.give_exercise(); // use's the pet class method
							break;
						case 3:
							PET.give_pets(); // use's the pet class method
							break;
						default:
							pet_interaction_menu = 0; // takes us out of the interaction loop
							break;
						}
					}
					break;
			
				case 2:					
					pet_setters_menu = 1;
					// displays the menu that will be used to change pet object properties.
					
					while (pet_setters_menu != 0) {
						cout << "Warning, changing these settings will change the image of your pet." << endl;
						cout << "What do you want to change? 0 = nothing, 1 = name, 2 = age, 3 = gender, 4 = race" << endl;
						cin >> setters_choice;
		
						switch(setters_choice) {
						
							case 1:
								cout << "Type your pet's new name: " << endl;
								cin >> pet_new_name; // user creates new name
								PET.set_name(pet_new_name); // pet class method using new name as an argument
								PET.get_name(); // display new name
								break;
							case 2:
								cout << "Type your pet's new age: " << endl;
								cin >> pet_new_age; // user creates new age
								PET.set_age(pet_new_age); // pet class method using new age as an argument
								PET.get_age(); // display new age
								break;
							case 3:
								cout << "Type your pet's new gender: " << endl;
								cin >> pet_new_gender; // user creates new gender
								PET.set_age(pet_new_gender); // pet class method using new gender as an argument
								PET.get_gender(); // display new gender
								break;
							case 4:
								cout << "Type your pet's new race: " << endl;
								cin >> pet_new_race; // user creates new race
								PET.set_race(pet_new_race); // pet class method using new race as an argument
								PET.get_race(); // display new race
								break;
							default:
								pet_setters_menu = 0; // takes us out of the pet_setters_menu loop
								break;
						}
					} break;
				
				case 3:
					task_list_setters_menu = 1;
					// displays the menu that will be used to change user object task_list.
					
					while (task_list_setters_menu != 0) {
						USER.get_task_list(); // displays the current task list
						cout <<  "Do you want to add an item to your task list? 0 = no, 1 = yes" << endl;
						cin >> task_list_choice;
						
						switch(task_list_choice) {
							case 1:
								cout << "What do you want to add?" << endl;
								cin >> add_item;
								
								USER.set_task_list_item(add_item); // user class method using new item as an argument
								cout << "Task list updated.";
								break;
							default:
								task_list_setters_menu = 0; // takes us out of the task_list_setters_menu loop
								break;
							}
						} break;
					
				case 4:
					task_list_removal_menu = 1;
					USER.get_task_list(); // displays the current task list
	
					while (task_list_removal_menu == 1) {
						cout << "Type the index of the item you wish to remove." << endl;
						cout << "If nothing is displayed, you currently don't have anything to do! (1000 to cancel)" << endl;
						cin >> remove_item;
						
						if (remove_item != 1000) {
							USER.remove_task_list_item(remove_item); // user class method using remove_item as an argument
						}
						break;
			} break;
				
				default:
					pet_menu_choice = 0; // closes the app
					break;
			}
			
			cout << "0 to close the app (will not save), 1 to stay" << endl; // double checks with the user to close the app or not
			cin >> keep_on;
			
			
			} while (keep_on != 0);
	return 0;
}