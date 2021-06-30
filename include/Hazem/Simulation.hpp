#ifndef HAZEM_SIMULATION
#define HAZEM_SIMULATION

#include <vector>
#include <map>

#include <Hazem/graphics.hpp>
#include <Hazem/physics.hpp>
#include <Hazem/HandlerParticle.hpp>
#include <Hazem/Util/Singleton.hpp>
#include <Hazem/Elements/Elements.hpp>

// #include "Events/EventHandler.hpp"


class Simulation
{
    enum arrowDrawType {
        NONE = 0,
        ACELERAION,
        EFIELD
    }ADS;

    uint32_t width, height;
    static Arrow defaultArrow;
    static Arrow defaultFieldArrow;
    
    bool running;
    bool pause;                 //pause simulation
    bool stopParticle;          //Stop particle drawing system
    
    arrowDrawType arrowStyle;   //Select witch vector style will be draw
    int EFIELD_OFFSET;          //Offset between each vector on eletric field
    std::vector<Arrow> vEfield;
    
    std::vector<std::string> vecUpdateQuery;
    sf::Font font;
    std::map<const char*, Text> mText;
    std::vector<ShapeBase*> shapes;
    HandlerParticle particleSystem;
    
    // INITIALIZE FUNCTIONS
    void init();
    bool initEField();
    bool initText();
    void initElement();

    void drawTextInfo();

    /// \brief Add a new Particle
    /// \param set true for a proton
    /// and false for eletron, and set initial position
    void addParticle(bool, const hz::Vector2&);

    void updateParticles();
    void updateField();

    void drawField();
public:
    
    sf::RenderWindow window;
    Simulation();
    Simulation(uint32_t, uint32_t);
    ~Simulation();

    bool start();
    void clear();
    /// \brief Reset the particles system
    void reset();
    void run();

    
};

#endif //!HAZEM_SIMULATION