#ifndef PLAYER_H
#define PLAYER_H

#include <string>

//#include "../Renderer.h"

#include "MovingGameObject.h"
#include "../Rect.h"
#include "../Point.h"

class Platform;
class Renderer;
class Projectile;

class Player : public MovingGameObject
{
  public:
    
  Player( Rect<int> r, Rect<int> c, std::string texturePath, int uniqueID , bool immune, int health, int damage, Projectile* currentProjectile);
  
  void Init(Point startpos, int uniquetag);
  
  void Reset();
  
  void HandleCollision(GameObject* otherObject) override;
  
  void Update();
  
  void Draw(Renderer* renderer);
  void renderPistol(Renderer* renderer);
  
  void movement_left();
  void movement_right();
  void movement_up();
  void movement_down();
  void movement_shoot();
  
  void JumpHandler();
  
  //GameObject* Clone() { return new Player(*this); }
  GameObject* Clone() { return new Player(*this); }
  
  void HandleAcceleration(GameObject* otherObject);
  
  ObjectType getType() { return GameObject::PLAYER; }
  
  private:
    
  const float m_jump_start_velocity;
  
  bool m_want_jump; 
  bool m_doubleJump_used;
  Point pistolHole;
  Point cameraAdjustment;
  
  float m_angle;
  
  int m_uniqueTag{10000};
  // PlayerState* currentState;
  
  Projectile* m_currentProjectile;
  
};

#endif