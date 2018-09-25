//
//  JUInspectorViewContainer.m
//  JUInspectorView
//
//  Copyright (c) 2011 by Sidney Just
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
//  documentation files (the "Software"), to deal in the Software without restriction, including without limitation 
//  the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
//  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
//  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
//  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import "JUInspectorViewContainer.h"
#import "JUInspectorView.h"

@interface JUInspectorView (JUInspectorViewPrivate)

-(void)updateBounds;

@end

@implementation JUInspectorViewContainer

#pragma mark - Init/Dealloc

- (void)setupView
{
    self.inspectorViews = [[NSMutableArray alloc] init];
}


#pragma mark - NSView override

- (void)setFrame:(NSRect)frameRect
{
    [super setFrame:frameRect];
    [self arrangeViews];
}

- (BOOL)isFlipped
{
    return YES;
}

- (void)drawRect:(NSRect)dirtyRect {
    [[NSColor whiteColor] set];
    NSRectFill(dirtyRect);
    [super drawRect:dirtyRect];
}


#pragma mark - Private methods

- (void)arrangeViews
{
    NSSortDescriptor *sortDescriptor = [NSSortDescriptor sortDescriptorWithKey:@"index" ascending:YES];
    [self.inspectorViews sortUsingDescriptors:@[sortDescriptor]];

    NSRect frame = NSMakeRect(0.0, 0.0, [self bounds].size.width, 0.0);
    
    for(JUInspectorView *view in self.inspectorViews)
    {
        frame.size.height = [view frame].size.height;
        
        [view setFrame:frame];
        
        frame.origin.y += frame.size.height;
    }
}


#pragma mark - Add/Remove Inspectors

- (void)addInspectorView:(JUInspectorView *)view expanded:(BOOL)expanded
{
    if(![self.inspectorViews containsObject:view])
    {
        [view setContainer:self];
        
        [self.inspectorViews addObject:view];
        [self addSubview:view];
        [self arrangeViews];
        
        view.expanded=expanded;
    }
}

- (void)addInspectorView:(JUInspectorView *)view atIndex:(NSInteger)index expanded:(BOOL)expanded
{
    [view setIndex:index];
    [self addInspectorView:view expanded:expanded];
}

- (void)removeInspectorView:(JUInspectorView *)view
{
    if([self.inspectorViews containsObject:view])
    {
        [view setContainer:self];
        
        [self.inspectorViews removeObject:view];
        [view removeFromSuperview];
        [self arrangeViews];
    }
}



@end