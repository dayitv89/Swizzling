# Swizzling
Objective C Swizzling : Category method override + inheritance mix concept

Method swizzling is the process of changing the implementation of an existing selector. It's a technique made possible by the fact that method invocations in Objective-C can be changed at runtime, by changing how selectors are mapped to underlying functions in a class's dispatch table.

For example, let's say we wanted to track how many times each view controller is presented to a user in an iOS app:

Each view controller could add tracking code to its own implementation of viewDidAppear:, but that would make for a ton of duplicated boilerplate code. Subclassing would be another possibility, but it would require subclassing UIViewController, UITableViewController, UINavigationController, and every other view controller class—an approach that would also suffer from code duplication.
