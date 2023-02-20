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
