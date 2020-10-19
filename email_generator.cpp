#include <iostream>
#include <fstream>

#include <experimental/random>

using namespace std;

void create_email(ofstream& ofs) {
    vector<string> senders {"John Doe", "Jane Doe", "G. Guy", "B. Guy",
        "Ethan Nagano", "Unknown Sender", "Secret Admirer"};
    int senders_size = senders.size();
    
    vector<string> recipients {"John Doe", "Jane Doe", "G. Guy", "B. Guy",
        "Ethan Nagano", "A. Stranger", "B. Stranger"};
    int recipients_size = recipients.size();
    
    vector<string> hosts {"<address1@somewhere.com>", 
        "<address2@somewhere.com>", "<address1@someplace.net>",
        "<address2@someplace.net>"};
    int hosts_size = hosts.size();
        
    vector<string> sample_subjects {"Hello", "URGENT: Bathroom Situation",
        "URGENT: Send Help", "Hello, world!", "Is this the end?", 
        "Regarding Your Workplace Review", "Prince in India with a Special Offer for You",
        "I'm Still Mad that the Dodgers Lost", "Have you seen my Husband?",
        "Derpy Hooves (Why did you leave us?)", "Have you seen my Wife?",
        "URGENT: Today's Test Results", "a meme", 
        "Please Read Regarding the Sending of Memes in the Workplace",
        "An update from the uh... boss man. Yeah.", "Ten Reasons C++ is Awesome",
        "Ten Reasons you Should Switch to Rust", 
        "Please Read Regarding Playing Fortnite in the Workplace", 
        "Bring Your Child to Work Day Clarification (This is for you, John)",
        "haha funny cat video", "haha funny mom meme"};
    int sample_subjects_size = sample_subjects.size();
    
    vector<string> sample_messages {"Hello.\nThis is a sample message.",
        "Hi.\nThis is a different sample message.", 
        "I want to schedule a meeting. Does 5:00 P.M. work for you?",
        "To my dearest,\n\tI love you.",
        "About your interaction with the boss today. What a jerk, right?",
        "This is a haiku\nThat spans three different lines.\nWorkplace artistry.",
        "I want to schedule a meeting. Does 1:00 A.M. work for you?",
        "To my (not so) dearest,\n\tI want a divorce.",
        "I\njust\ndiscovered\nthe\nenter\nkey.\nIsn't\nthis\ngreat?",
        "Your mom called. She wants her money back."};
    int sample_messages_size = sample_messages.size();
    
    string line_end {"––––"};
    
    
    
    string sender = senders[experimental::randint(0, senders_size-1)];
    string recipient = recipients[experimental::randint(0, recipients_size-1)];
    string host1 = hosts[experimental::randint(0, hosts_size-1)];
    string host2 = hosts[experimental::randint(0, hosts_size-1)];
    string subject = sample_subjects[experimental::randint(0, sample_subjects_size-1)];
    string message = sample_messages[experimental::randint(0, sample_messages_size-1)];
    
    ofs << "From: " << sender << " " << host1 << "\n"
       << "To: " << recipient << " " << host2 << "\n"
       << "Subject: " << subject << "\n\n"
       << message << "\n"
       << line_end << "\n\n";
}

int main() {
    
    ofstream emails {"mail_file_3.txt"};
    
    for (int i = 0; i < 20000; ++i) {
        create_email(emails);
    }
    
    return 0;
}
