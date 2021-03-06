// The MIT License
//
// Copyright (c) 2014 Gwendal Roué
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "GRMustacheAvailabilityMacros_private.h"
#import "GRMustacheContentType.h"
#import "GRMustacheASTVisitor_private.h"

/**
 * The GRMustacheAST represents the abstract syntax tree of a template.
 */
@interface GRMustacheAST : NSObject {
@private
    NSArray *_ASTNodes;
    GRMustacheContentType _contentType;
}

/**
 * An NSArray containing <GRMustacheASTNode> instances
 *
 * @see GRMustacheASTNode
 */
@property (nonatomic, retain) NSArray *ASTNodes GRMUSTACHE_API_INTERNAL;

/**
 * The content type of the AST
 */
@property (nonatomic) GRMustacheContentType contentType GRMUSTACHE_API_INTERNAL;

/**
 * Used by GRMustacheTemplateRepository, which uses placeholder ASTs when
 * building recursive templates.
 */
@property (nonatomic, readonly, getter = isPlaceholder) BOOL placeholder GRMUSTACHE_API_INTERNAL;

/**
 * Returns a new allocated AST.
 *
 * @param ASTNodes     An array of <GRMustacheASTNode> instances.
 * @param contentType  A content type
 *
 * @return A new GRMustacheAST
 *
 * @see GRMustacheASTNode
 */
+ (instancetype)ASTWithASTNodes:(NSArray *)ASTNodes contentType:(GRMustacheContentType)contentType GRMUSTACHE_API_INTERNAL;

/**
 * Returns a placeholder AST
 * @see placeholder
 */
+ (instancetype)placeholderAST GRMUSTACHE_API_INTERNAL;

@end

