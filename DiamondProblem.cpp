/*A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class by using a common abstract base class. 
This is also called cross delegation. 
Let's assume we have a similar scenario like in the diamond example, with small changes. 
Suppose the write() method in transmitter class needs to access the read() method from receiver for the radio to work (this is kind of a weird behavior, 
but let's take it for the sake of illustration) : */
class storable 
{
        public:
        storable(const char*);
        virtual void read()=0; //this becomes pure virtual making storable an abstract
        virtual void write(); //class
        virtual ~storable();
        private:
        
}

class transmitter: public virtual storable 
{
        public:
        void write()
        {
                read();
         
        }
} 

class receiver: public virtual storable
{
        public:
        void read();
}

class radio: public transmitter, public receiver
{
        public:
        
}

int main()
{
        radio *rad = new radio();
        receiver *r1 = rad;
        transmitter *r2 =rad;

        rad->write();
        r1->write();
        r2->write();
        return 1;
}
