//
//  SKAction+JSExport.h
//  PencilCaseJSDemo
//
//  Created by Brandon on 1/6/2014.
//  Copyright (c) 2014 RobotsAndPencils. All rights reserved.
//

@import SpriteKit;
@import JavaScriptCore;

@protocol SKActionExport <JSExport>

@property (nonatomic, assign) NSTimeInterval duration;
@property (nonatomic, assign) SKActionTimingMode timingMode;
@property (nonatomic, assign) CGFloat speed;

- (SKAction *)reversedAction;

+ (SKAction *)moveByX:(CGFloat)deltaX y:(CGFloat)deltaY duration:(NSTimeInterval)sec;
+ (SKAction *)moveBy:(CGVector)delta duration:(NSTimeInterval)sec;
+ (SKAction *)moveTo:(CGPoint)location duration:(NSTimeInterval)sec;
+ (SKAction *)moveToX:(CGFloat)x duration:(NSTimeInterval)sec;
+ (SKAction *)moveToY:(CGFloat)y duration:(NSTimeInterval)sec;

+ (SKAction *)rotateByAngle:(CGFloat)radians duration:(NSTimeInterval)sec;
+ (SKAction *)rotateToAngle:(CGFloat)radians duration:(NSTimeInterval)sec;
+ (SKAction *)rotateToAngle:(CGFloat)radians duration:(NSTimeInterval)sec shortestUnitArc:(BOOL)shortestUnitArc;

+ (SKAction *)resizeByWidth:(CGFloat)width height:(CGFloat)height duration:(NSTimeInterval)duration;
+ (SKAction *)resizeToWidth:(CGFloat)width height:(CGFloat)height duration:(NSTimeInterval)duration;

+ (SKAction *)resizeToWidth:(CGFloat)width duration:(NSTimeInterval)duration;
+ (SKAction *)resizeToHeight:(CGFloat)height duration:(NSTimeInterval)duration;

+ (SKAction *)scaleBy:(CGFloat)scale duration:(NSTimeInterval)sec;
+ (SKAction *)scaleXBy:(CGFloat)xScale y:(CGFloat)yScale duration:(NSTimeInterval)sec;
+ (SKAction *)scaleTo:(CGFloat)scale duration:(NSTimeInterval)sec;
+ (SKAction *)scaleXTo:(CGFloat)xScale y:(CGFloat)yScale duration:(NSTimeInterval)sec;
+ (SKAction *)scaleXTo:(CGFloat)scale duration:(NSTimeInterval)sec;
+ (SKAction *)scaleYTo:(CGFloat)scale duration:(NSTimeInterval)sec;

+ (SKAction *)sequence:(NSArray *)actions;

+ (SKAction *)group:(NSArray *)actions;

+ (SKAction *)repeatAction:(SKAction *)action count:(NSUInteger)count;
+ (SKAction *)repeatActionForever:(SKAction *)action;

+ (SKAction *)fadeInWithDuration:(NSTimeInterval)sec;
+ (SKAction *)fadeOutWithDuration:(NSTimeInterval)sec;
+ (SKAction *)fadeAlphaBy:(CGFloat)factor duration:(NSTimeInterval)sec;
+ (SKAction *)fadeAlphaTo:(CGFloat)alpha duration:(NSTimeInterval)sec;

+ (SKAction *)setTexture:(SKTexture *)texture;
+ (SKAction *)animateWithTextures:(NSArray *)textures timePerFrame:(NSTimeInterval)sec;
+ (SKAction *)animateWithTextures:(NSArray *)textures timePerFrame:(NSTimeInterval)sec resize:(BOOL)resize restore:(BOOL)restore;

/* name must be the name or path of a file of a platform supported audio file format. Use a LinearPCM format audio file with 8 or 16 bits per channel for best performance */
+ (SKAction *)playSoundFileNamed:(NSString*)soundFile waitForCompletion:(BOOL)wait;

+ (SKAction *)colorizeWithColor:(SKColor *)color colorBlendFactor:(CGFloat)colorBlendFactor duration:(NSTimeInterval)sec;
+ (SKAction *)colorizeWithColorBlendFactor:(CGFloat)colorBlendFactor duration:(NSTimeInterval)sec;

+ (SKAction *)followPath:(CGPathRef)path duration:(NSTimeInterval)sec;
+ (SKAction *)followPath:(CGPathRef)path asOffset:(BOOL)offset orientToPath:(BOOL)orient duration:(NSTimeInterval)sec;

+ (SKAction *)speedBy:(CGFloat)speed duration:(NSTimeInterval)sec;
+ (SKAction *)speedTo:(CGFloat)speed duration:(NSTimeInterval)sec;

+ (SKAction *)waitForDuration:(NSTimeInterval)sec;
+ (SKAction *)waitForDuration:(NSTimeInterval)sec withRange:(NSTimeInterval)durationRange;

+ (SKAction *)removeFromParent;

+ (SKAction *)performSelector:(SEL)selector onTarget:(id)target;

+ (SKAction *)runBlock:(dispatch_block_t)block;
+ (SKAction *)runBlock:(dispatch_block_t)block queue:(dispatch_queue_t)queue;

+ (SKAction *)runAction:(SKAction *)action onChildWithName:(NSString*)name;

+ (SKAction *)customActionWithDuration:(NSTimeInterval)seconds actionBlock:(void (^)(SKNode *node, CGFloat elapsedTime))block;

@end

@interface SKAction (JSExport) <SKActionExport>

@end
